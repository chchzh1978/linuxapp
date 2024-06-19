#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char *argv[])
{
    int fd, retvalue;
    char *filename;
    unsigned char databuf[1];
    unsigned char readbuf[13];

    if(argc != 3)
    {
        printf("Error Usage!\r\n");
        return -1;
    }

    filename = argv[1];

    fd = open(filename, O_RDWR);
    if(fd < 0)
    {
        printf("file %s open failed!\r\n", argv[1]);
        return -1;
    }
    databuf[0] = atoi(argv[2]); /* 要执行的操作：打开或关闭 */
    if(databuf[0] ==  2)
    {
         retvalue = read(fd,readbuf,sizeof(readbuf));
        if(retvalue < 0)
        {
            printf("read file %s failed!\r\n",filename);
        }
        else
        {
            //printf("read date: %x\r\n",readbuf[0]);
            printf("rea date: %s\r\n",readbuf);
        }
    }else
    {
         /* 向/dev/hello_word 文件写入数据 */
        retvalue = write(fd, databuf, sizeof(databuf));
        if(retvalue < 0)
        {
            printf("LED Control Failed!\r\n");
            close(fd);
            return -1;
        }
    }
   
    retvalue = close(fd);
    if(retvalue < 0)
    {
        printf("file %s close failed!\r\n", argv[1]);
        return -1;
    }
    return 0;
}
