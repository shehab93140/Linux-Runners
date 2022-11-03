#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>

typedef struct
{
    u_int8_t status;
    uint8_t first_chs[3];
    u_int8_t partition_types;
    u_int8_t last_chs[3];
    uint32_t lba;
    uint32_t sector_count;
} TableEntry;

typedef struct
{
    u_int8_t status;
    uint8_t first_chs_EBR[3];
    u_int8_t partition_types_EBR;
    u_int8_t last_chs_EBR[3];
    uint32_t lba_EBR;
    uint32_t partition_size;
} EBR_partition;

int main(int argc, char **argv)
{
    char buf[512];
    if (argc != 2)
    {
        printf("Error \n");
        return 0;
    }
    else
    {
        int fd = open(argv[1], O_RDONLY);
        read(fd, buf, 512);
       
        TableEntry *table_entry_ptr = (TableEntry *)&buf[446];
        
        printf("Device\tBoot\tStart\tEnd\tSectors\tSize\tId\tType\n");

        for (int i = 0; i < 4; i++)
        {

            if (table_entry_ptr[i].sector_count == 0){}
            else
            {
                printf("%s%d\t%c\t%u\t%u\t%u\t%0.1fk\t%x",
                       argv[1],
                       i + 1,
                       table_entry_ptr[i].status == 0x80 ? '*' : '0',
                       table_entry_ptr[i].lba, table_entry_ptr[i].lba + table_entry_ptr[i].sector_count - 1, table_entry_ptr[i].sector_count,
                       (((uint64_t)table_entry_ptr[i].sector_count *
                         512.0) /
                        (1024.0)),
                       table_entry_ptr[i].partition_types);
                printf("\n");
            

            }
        }
        
    
       
    }
    return 0;
}
