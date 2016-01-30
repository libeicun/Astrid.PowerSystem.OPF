#pragma once
#include "pf_calc_def_data_type.h"
#include "pf_calc_sys_cfg.h"

class CPfCalcNode{
public:
	pf_uint32							index;
	PF_CALC_DATA_TYPE		e;//δ֪��
	PF_CALC_DATA_TYPE		f;//δ֪��

	CPfCalcNode();
	virtual ~CPfCalcNode();
};

class CPfCalcNodePq : public CPfCalcNode
{
public:
	PF_CALC_DATA_TYPE		P;//��֪��
	PF_CALC_DATA_TYPE		Q;//��֪��
	pf_uint32 offset;//Use for Jacorb Matrix and .deltaPQPU2[] and deltaEF[];
	pf_uint32	offset2;//Use for .aii[] and .bii[]
	CPfCalcNodePq();
	virtual ~CPfCalcNodePq();
private:

};
class CPfCalcNodePv : public CPfCalcNode
{
public:
	PF_CALC_DATA_TYPE		P;//��֪��
	PF_CALC_DATA_TYPE		Ql;//��֪��
	PF_CALC_DATA_TYPE		Qg;//δ֪��
	PF_CALC_DATA_TYPE		U2;//��֪��
	pf_uint32 offset;//Use for Jacorb Matrix and .deltaPQPU2[] and deltaEF[];
	pf_uint32	offset2;//Use for .aii[] and .bii[]
	CPfCalcNodePv();
	virtual ~CPfCalcNodePv();
private:
};

class CPfCalcNodeBl : public CPfCalcNode
{
public:

	PF_CALC_DATA_TYPE	Pl;//��֪��
	PF_CALC_DATA_TYPE	Ql;//��֪��
	PF_CALC_DATA_TYPE	Pg;//δ֪��
	PF_CALC_DATA_TYPE	Qg;//δ֪��
	pf_uint32 offset;//Use for Jacorb Matrix and .deltaPQPU2[] and deltaEF[];
	pf_uint32	offset2;//Use for .aii[] and .bii[]
	CPfCalcNodeBl();
	virtual ~CPfCalcNodeBl();
private:
};




/*�ڵ����Ͷ���*/
enum ePfNodeClass
{
	ePfNodeClassPV,
	ePfNodeClassPQ,
	ePfNodeClassBL,
};
class CComplex
{
public:
	PF_CALC_DATA_TYPE real;
	PF_CALC_DATA_TYPE image;
	CComplex();
	virtual ~CComplex();
}
;


