/********************************************************************
created:	2016/03/29
author:		Zhang Yanfeng
e-mail:     zhang_yanfeng_3d@foxmail.com
purpose:	This file is for enegy optimization with semi-global optimization.
*********************************************************************/
#ifndef _PIXELLABSGO_H_
#define _PIXELLABSGO_H_
#include <windows.h>

#ifdef PIXELLABSGO_EXPORTS
#define PIXELLABSGO_API _declspec(dllexport)
#else

#ifndef _X64
#define PIXELLABSGO_API _declspec(dllimport)
#pragma comment(lib,"PixelLabSGO.lib")
#pragma message("Automatically linking width PixelLabSGO.lib")

#else

#define PIXELLABSGO_API _declspec(dllimport)
#pragma comment(lib,"PixelLabSGO_x64.lib")
#pragma message("Automatically linking width PixelLabSGO_x64.lib")
#endif

#endif

/*****************����˵��***************/
//��������SimpleGlobalAggregation
//���ܣ�������Ĵ��۾�����а�ȫ�ֻ���
//����˵����
//costmatrix��������۾�����ά���飬ά��Ϊwidth*height*numLevel
//width��ͼ����
//height��ͼ��߶�
//numLevel�������Ŀ
/*****************����˵��***************/
PIXELLABSGO_API void SimpleGlobalAggregation(float *costmatrix, int width, int height, int numLevel,
	float p1 = 0.3, float p2 = 1.2);

/*****************����˵��***************/
//��������ImageGuidedSemiGlobalAggregation
//���ܣ�������Ĵ��۾����������Ӧ�ͷ��İ�ȫ�ֻ��ۣ�רΪ����������DSMƥ�����
//����˵����
//costmatrix��������۾�����ά���飬ά��Ϊwidth*height*numLevel
//bufImg������������ͼ�񣬶�ά���飬ά��Ϊwidth*heihgt
//weight������Ȩ�����飬��ά���飬ά��Ϊwidth*height
//width��ͼ����
//height��ͼ��߶�
//numLevel�������Ŀ
//p1:ƽ���ͷ�1��p2:ƽ���ͷ�2��p3:����������ͷ�����ϵ����p4:����������Ԫ����ֵ
/*****************����˵��***************/
PIXELLABSGO_API void ImageGuidedSemiGlobalAggregation(float *costmatrix, unsigned char *bufImg, int width, int height, int numLevel,
	float p1 = 0.3, float p2 = 1.2, float p3 = 2.0, int p4 = 100);

/*****************����˵��***************/
//��������HierSimpleGlobalAggregation
//���ܣ�������Ĵ��۾�����а�ȫ�ֻ���
//����˵����
//costmatrix��������۾�����ά���飬ά��Ϊwidth*height*numLevel
//width��ͼ����
//height��ͼ��߶�
//numLevel�������Ŀ
//initlabel:��ʼ��ţ���¼��С���
//wholerange:������ŷ�Χ
//p1��p2:�ͷ�
/*****************����˵��***************/
PIXELLABSGO_API void HierSimpleGlobalAggregation(float *costmatrix, int width, int height, int numLevel, int* initlabel, int wholerange,
	float p1 = 0.3, float p2 = 1.2);

/*****************����˵��***************/
//��������HierSemiGlobalAggregation
//���ܣ�������Ĵ��۾�����б��߽�������ȫ�ֻ���
//����˵����
//costmatrix��������۾�����ά���飬ά��Ϊwidth*height*numLevel
//width��ͼ����
//height��ͼ��߶�
//numLevel�������Ŀ
//initlabel:��ʼ��ţ���¼��С���
//range:��ʼ��ŷ�Χ��[initlabel,initlabel+numLevel]
//wholerange:������ŷ�Χ
//p1��p2:�ͷ�
/*****************����˵��***************/
PIXELLABSGO_API void HierSemiGlobalAggregation(float *costmatrix, int width, int height, int* initlabel, int *range, int wholerange,
	float p1 = 0.3, float p2 = 1.2);
/*****************����˵��***************/
//��������HierImageGuidedSemiGlobalAggregation
//���ܣ�������Ĵ��۾����������Ӧ�ͷ��İ�ȫ�ֻ��ۣ��������������ǿƽ��Լ����רΪ����������DSMƥ�����
//����˵����
//costmatrix��������۾�����ά���飬ά��Ϊwidth*height*numLevel
//bufImg������������ͼ�񣬶�ά���飬ά��Ϊwidth*heihgt
//weight������Ȩ�����飬��ά���飬ά��Ϊwidth*height
//width��ͼ����
//height��ͼ��߶�
//numLevel�������Ŀ
//p1:ƽ���ͷ�1��p2:ƽ���ͷ�2��p3:����������ͷ�����ϵ����p4:����������Ԫ����ֵ
/*****************����˵��***************/
PIXELLABSGO_API void HierImageGuidedSemiGlobalAggregation(float *costmatrix, unsigned char *bufImg, int width, int height, int numLevel, int* initlabel, int wholerange,
	float p1 = 0.3, float p2 = 1.2, float p3 = 2.0, int p4 = 100);

/*****************����˵��***************/
//��������SegmentConstrainedSemiGlobalAggregation
//���ܣ�������Ĵ��۾�����зָ�Լ���İ�ȫ�ֻ��ۣ����ָ���������רΪ�ָ�Լ����DSM�˲����
//����˵����
//costmatrix��������۾�����ά���飬ά��Ϊwidth*height*numLevel
//segflag������ָ��ǣ���ά���飬ά��Ϊwidth*heihgt
//gamma:������Ȩ�أ�ά��Ϊwidth*height
//weight������Ȩ�����飬��ά���飬ά��Ϊwidth*height
//width��ͼ����
//height��ͼ��߶�
//numLevel�������Ŀ
/*****************����˵��***************/
PIXELLABSGO_API void SegmentConstrainedSemiGlobalAggregation(float *costmatrix, int* segflag, float *gamma, int width, int height, int numLevel,
	float p1 = 0.3, float p2 = 1.2);

/*****************����˵��***************/
//��������PixelwiseSmoothSemiGlobalAggregation
//���ܣ�������Ĵ��۾������������ƽ���İ�ȫ�ֻ���
//����˵����
//costmatrix��������۾�����ά���飬ά��Ϊwidth*height*numLevel
//width��ͼ����
//height��ͼ��߶�
//numLevel�������Ŀ
/*****************����˵��***************/
PIXELLABSGO_API void PixelwiseSmoothSemiGlobalAggregation(float *costmatrix, int width, int height, int numLevel);

/*****************����˵��***************/
//��������NovelSimpleGlobalAggregation
//���ܣ�������Ĵ��۾�����ж��װ�ȫ�ֻ���
//����˵����
//costmatrix��������۾�����ά���飬ά��Ϊwidth*height*numLevel
//width��ͼ����
//height��ͼ��߶�
//numLevel�������Ŀ
/*****************����˵��***************/
PIXELLABSGO_API void NovelSimpleGlobalAggregation(float *costmatrix, int width, int height, int numLevel,
	float p1 = 0.3, float p2 = 1.2);

/*****************����˵��***************/
//��������NovelSimpleGlobalAggregation
//���ܣ�������Ĵ��۾�����е��������Ķ��װ�ȫ�ֻ���
//����˵����
//costmatrix��������۾�����ά���飬ά��Ϊwidth*height*numLevel
//width��ͼ����
//height��ͼ��߶�
//numLevel�������Ŀ
/*****************����˵��***************/
PIXELLABSGO_API void NovelHierSimpleGlobalAggregation(float *costmatrix, int width, int height, int numLevel, int* initlabel, int wholerange,
	float p1 = 0.3, float p2 = 1.2);
#endif