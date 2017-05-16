/********************************************************************
created:	2016/03/20
author:		Zhang Yanfeng
e-mail:     zhang_yanfeng_3d@foxmail.com
purpose:	This file is for check speckle
*********************************************************************/
#ifndef _PIXELLABSPECKLECHECKER_H_
#define _PIXELLABSPECKLECHECKER_H_
#include <windows.h>

#ifdef PIXELLABSPECKLECHECKER_EXPORTS
#define PIXELLABSPECKLECHECKER_API _declspec(dllexport)
#else

#ifndef _X64
#define PIXELLABSPECKLECHECKER_API _declspec(dllimport)
#pragma comment(lib,"PixelLabSpeckleChecker.lib")
#pragma message("Automatically linking width PixelLabSpeckleChecker.lib")

#else

#define PIXELLABSPECKLECHECKER_API _declspec(dllimport)
#pragma comment(lib,"PixelLabSpeckleChecker_x64.lib")
#pragma message("Automatically linking width PixelLabSpeckleChecker_x64.lib")
#endif

#endif
/*****************����˵��***************/
//��������BinaryRemoveSpeckle
//���ܣ��������ֵͼ��ȥ����Ƭ
//����˵����
//buf�������ֵͼ������
//width��DSM�Ŀ��
//height��DSM�ĸ߶�
//p���Ƴ���Ƭ��С������������Ŀ��С�ڸ�ֵ����Ƭ�����Ƴ�
/*****************����˵��***************/
PIXELLABSPECKLECHECKER_API void BinaryRemoveSpeckle(unsigned char* buf, int width, int height, int p = 100, int type = 1);

/*****************����˵��***************/
//��������RemoveSpeckle
//���ܣ������븡����ͼ��ȥ����Ƭ
//����˵����
//buf�����븡����ͼ������
//width��DSM�Ŀ��
//height��DSM�ĸ߶�
//p1����ͨ��ֵ
//p2���Ƴ���Ƭ��С������������Ŀ��С�ڸ�ֵ����Ƭ�����Ƴ�
/*****************����˵��***************/
PIXELLABSPECKLECHECKER_API void RemoveSpeckle(float* buf, int width, int height, float p1 = 1.0, int p2 = 100);

/*****************����˵��***************/
//��������RegionGrow
//���ܣ������븡����ͼ��������ӵ��������
//����˵����
//buf�����븡����ͼ������
//width��DSM�Ŀ��
//height��DSM�ĸ߶�
//p1����ͨ��ֵ1������
//p2����ͨ��ֵ2������
/*****************����˵��***************/
PIXELLABSPECKLECHECKER_API void RegionGrow(float* buf, unsigned char *mask, int width, int height, float p1 = -1.0, float p2 = 1.0);

/*****************����˵��***************/
//��������Cluster4Segmentation
//���ܣ�������ķָ�ͼ����о��࣬���������
//����˵����
//seg������ָ�ͼ��
//width��ͼ����
//height��ͼ��߶�
//num_cluster��������Ԫ������num_cluster[i]��ʾ��i����������Ԫ����Ŀ����Ҫ���������ڴ�
//x_cluster��������֮x���꣬��������˳��洢����Ҫ���������ڴ�
//y_cluster��������֮y���꣬��������˳��洢����Ҫ���������ڴ�
//p������Ԫ������
/*****************����˵��***************/
PIXELLABSPECKLECHECKER_API int Cluster4Segmentation(int* seg, int width, int height, int *num_cluster, int *x_cluster, int *y_cluster, int p = 9999999);

/*****************����˵��***************/
//��������Segmentation
//���ܣ�������ĻҶ�ͼ����зָ���࣬���������
//����˵����
//seg������Ҷ�ͼ��
//width��ͼ����
//height��ͼ��߶�
//num_cluster��������Ԫ������num_cluster[i]��ʾ��i����������Ԫ����Ŀ����Ҫ���������ڴ�
//x_cluster��������֮x���꣬��������˳��洢����Ҫ���������ڴ�
//y_cluster��������֮y���꣬��������˳��洢����Ҫ���������ڴ�
//p������Ԫ������
/*****************����˵��***************/
PIXELLABSPECKLECHECKER_API int Segmentation(unsigned char* buf, int width, int height, int *num_cluster, int *x_cluster, int *y_cluster, int p = 9999999);

/*****************����˵��***************/
//��������Extract4Segmentation
//���ܣ�������ĸ�����ͼ���ڷָ�ͼ�����������£����ɷָ�������Сֵ
//����˵����
//buf���������ȡ��Ϣ������ͼ��
//min������ָ����Сֵ
//max������ָ�����ֵ
//seg������ָ�ͼ��
//width��ͼ����
//height��ͼ��߶�
//p1���ָ��Ԫ��������
//p2���ָ��Ԫ��������
/*****************����˵��***************/
PIXELLABSPECKLECHECKER_API int Extract4Segmentation(float* buf, float* min, float *max, int* seg, int width, int height, int p1 = 80, int p2 = 9999999);

/*****************����˵��***************/
//��������Extract4Segmentation
//���ܣ������������ͼ���ڷָ�ͼ�����������£����ɷָ�������Сֵ
//����˵����
//buf���������ȡ��Ϣint��ͼ��
//min������ָ����Сֵ
//max������ָ�����ֵ
//seg������ָ�ͼ��
//width��ͼ����
//height��ͼ��߶�
//p1���ָ��Ԫ��������
//p2���ָ��Ԫ��������
/*****************����˵��***************/
PIXELLABSPECKLECHECKER_API int Extract4Segmentation(int* buf, int* min, int *max, int* seg, int width, int height, int p1 = 80, int p2 = 9999999);
#endif