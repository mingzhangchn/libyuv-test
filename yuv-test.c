
#include <stdio.h>
#include <string.h>
#include <libyuv.h>


int main()
{
    FILE *fp=fopen("out.yuv","rb+");
    FILE *fp1=fopen("output_420.yuv","wb+");
    int w = 640;
    int h = 480;
    
    unsigned char *src_yuy2=(unsigned char *)malloc(w*h*2);
    
    int p420size = w * h + (w*h + 1)/2;
    unsigned char * pI420 = malloc (p420size);
    
    int i = 0;
    while(fread(src_yuy2,1,w*h*2,fp) > 0){
        memset(pI420, 0, p420size);
        unsigned char* dst_y = pI420;
        int dst_y_stride = w;
        unsigned char* dst_u = pI420 + w*h;
        int dst_u_stride = (w + 1) / 2;
        unsigned char* dst_v = pI420 + w*h + (w*h +3)/4;
        int dst_v_stride = (w + 1) / 2;
        
        YUY2ToI420(src_yuy2, w*2, dst_y, dst_y_stride, dst_u, dst_u_stride, dst_u, dst_v_stride, w, h);
        fwrite(pI420, p420size, 1, fp1);
        i++;
        printf("%d\n", i);
    }
    
    free(pI420);
    free(src_yuy2);
    fclose(fp);
    fclose(fp1);
    
    return 0;
}