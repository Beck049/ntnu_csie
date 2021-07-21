#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <math.h>


// struct option {
//     const char *name  ; // name of the long option
//
//     int        has_arg; // 0 : no argument
//                         // 1 : required arguments
//                         // 2 : optional arguments
//
//     int        *flag  ; // specify how results are returned
//                         // if flag == NULL
//                         //   getopt_long will return val
//                         // else
//                         //   getopt_long will return 0
//                         //   and flag == val
//                            
//     int        val    ; // the value to return
// };

struct option long_options[] = 
{
    {"split"  , 1, NULL, 's' },
    {"recover", 1, NULL, 'r' },
    {"size"   , 1, NULL, 'z' },
    {"help"   , 0, NULL, 'h' },
    {0, 0, 0, 0}
};

int main(int argc, char *argv[])
{
    int32_t c = 0;
    int32_t ridx = 0;
    // opening keys ( 1 to trigger )
    int32_t opt_s = 0, opt_r = 0, opt_size = 0, opt_help = 0;
    // files
    FILE* file_origin   = NULL;     char filename_origin  [32] = "";
    FILE* file_modified = NULL;     char filename_modified[32] = "";
    FILE* file_recover  = NULL;     char filename_recover [32] = "";
  
    char input_size[32] = "";

    uint8_t* buf = NULL;
    uint32_t num = 0;
    int32_t cnt = 0; // size of the buffer
    int64_t filesize = 0;
    uint64_t size = 1000;// default
    char* pEnd ;// for strtol


    while( (c = getopt_long(argc,argv,"s:r:z:h",long_options,NULL)) != -1 )
    // -s [filename] to split  // -r [out] [small] to recover  
    //  --size [size]          //  --help  (print texts)
    {
        switch(c){
            case 's':
                opt_s = 1;
                strncpy(filename_origin,optarg,32);
                break;
            case 'r':
                opt_r = 1;
                strncpy(filename_recover,optarg,32);
                ridx = optind;
                break;
            case 'z':
                opt_size = 1;
                strncpy(input_size,optarg,32);
                break;
            case 'h':
                opt_help = 1;
                break;
        }
    }


    if( opt_size == 1 )
    {   size = (uint64_t)strtol(input_size,&pEnd,10); }
    //  trans the size from string form to integer form

    if( opt_s == 1 )
    {
        if( (file_origin = fopen(filename_origin,"r")) == NULL )
        {
            perror("Error");
            return 0;
        }
    
    // seek for the EOF, return is the size of the file
        fseek(file_origin,0,SEEK_END);
        filesize = ftell(file_origin);
    // point back to the head, in order to read l8r
        rewind(file_origin);
    // open space
        num = (uint32_t)ceil(((double)filesize / size));
        buf = (uint8_t*)malloc(sizeof(uint8_t) * size);
    
    // write into num files
        for(uint32_t i = 1 ; i <= num; i++)
        {
        // set file name : origin_name.i
            strncpy(filename_modified,filename_origin,32);
            filename_modified[strlen(filename_modified)] = '.';
            //**snprintf**
            snprintf(&filename_modified[strlen(filename_modified)],31 - strlen(filename_modified),"%u",i);

            file_modified = fopen(filename_modified,"wb");
        // write header ... 4 byte for i (enum the file) // 8 byte for size (in string)
            fwrite(&i,sizeof(i),1,file_modified);
            fwrite(&size,sizeof(size),1,file_modified);
        // read all required file at once *** in readme ***
        // and write in the new file
            cnt = fread(buf,1,size,file_origin);
            fwrite(buf,1,cnt,file_modified);
            printf("%s ",filename_modified);
            fclose(file_modified);
        }

        printf("\n");

        free(buf);
        fclose(file_origin);

    }


    if( opt_r == 1 )
    {
        if((file_recover = fopen(filename_recover,"wb")) == NULL)
        {
            perror("Error");
            return 0;
        }

        while(ridx < argc && argv[ridx][0] != '-')
        //      except "-r"  and  not other operator
        {    
            if((file_origin = fopen(argv[ridx],"rb")) == NULL)
            {
                perror("Error");
                return 0;
            }
        // remember header ... 
        // 4 byte for i (enum the file) // 8 byte for size (in string)
            fread(&num,sizeof(num),1,file_origin);
            fread(&size,sizeof(size),1,file_origin);
        // open space
            buf = (uint8_t*)malloc(sizeof(uint8_t) * size);
            cnt = fread(buf,1,size,file_origin);
        // read/write the content from current (after header)
            fseek(file_recover,size * (num - 1),SEEK_SET);
            fwrite(buf,1,cnt,file_recover);

            fclose(file_origin);          
        // go to another file_name
            ridx++;

            free(buf);
        }

        fclose(file_recover);
    }

    if( opt_help == 1 )
    {// print all avaliable operator // split // size // recover //
        printf("Split:\n");
        printf("./hw0401 -s [file] --size [Small File Size]\n");
        printf("The default small file size is 1000 bytes.\n");
        printf("Recover:\n");
        printf("./hw0401 -r [output file] [small files]\n");
        printf("The input small files may not be in order.\n");
    }

    return 0;
}