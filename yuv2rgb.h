/**
 * @file   yuv2rgb.h
 * @author Late Lee
 * @date   2012.01.20
 * 
 * @brief  
 *         YUV422P/YUV420PתRGB24ʵ�ִ��룬�����Ժ���
 *
 * @note
 *         1����Windows�������
 *         2��������ʹ�õ�YUV420P��YUV422P��ƽ��(planar)��ʽ�����Ǵ��(packed)��ʽ
 *
 *         3��qcif: 176*144
              cif: 352*288

  * �ʼǣ�
            ÿ��Y��U��V��R��G��B��ռ��1���ֽ�
            YUV422Pƽ���ʽ
            Y��U��V�ֿ��洢��Yռw*h��U��V�ֱ�ռw*h/2��ÿ��Y��w����U��V��w/2����
            ����Y����һ��U��V������������Y����2����U��V������һ������4�ֽڣ����һ������ռ2�ֽڡ�

            �ڴ�ֲ����£�
                    w
            +--------------------+
            |Y0Y1Y2Y3...         |
            |...                 |   h
            |...                 |
            |                    |
            +--------------------+
            |U0U1      |
            |...       |   h
            |...       |
            |          |
            +----------+
            |V0V1      |
            |...       |  h
            |...       |
            |          |
            +----------+
                w/2

            ��һ�����أ�Y0 U0 V0
            �ڶ������أ�Y1 U0 V0
            ���������أ�Y2 U1 V1
            ���ĸ����أ�Y3 U1 V1
 */

#ifndef _YUV2RGB_H_
#define _YUV2RGB_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  YUV422P��
 * 
 * @param  no
 * 
 * @return no
 */
void init_yuv422p_table(void);

/**
 * @brief  YUV422Pת��ΪRGB24(���)
 * 
 * @param  yuvbuffer[IN]    YUV422Pƽ���ʽ������
 * @param  rgbbuffer[OUT]   RGB������
 * @param  width[IN]        ͼ���
 * @param  height[IN]       ͼ���
 * 
 * @return no
 *
 * @note
 *         1.YUV422P��ʽYUV��������СΪw * h * 2
 *         2.rgbbuffer��������ΪRGB���籣��BMP����Ҫ����ΪBGR
 */
void yuv422p_to_rgb24(unsigned char* yuvbuffer, unsigned char* rgbbuffer, int width, int height);

/**
 * @brief  YUV420P��
 * 
 * @param  no
 * 
 * @return no
 */
void init_yuv420p_table();
/** 
 * @brief YUV420PתRGB24(���)
 * 
 * @param yuvbuffer  YUV420P��ʽ������
 * @param rgbbuffer  RGB24��ʽ������
 * @param width      ͼ���
 * @param height     ͼ���
 *
 *
 * @note
 *        1��YUV420P��ʽYUV��������СΪw * h * 3 / 2
 *        2��rgbbuffer��������ΪRGB���籣��BMP����Ҫ����ΪBGR
 */
void yuv420p_to_rgb24(unsigned char* yuvbuffer,unsigned char* rgbbuffer, int width, int height);

#ifdef __cplusplus
}
#endif

#endif /* _YUV2RGB_H_ */