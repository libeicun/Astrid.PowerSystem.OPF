#include "PfCalcNode.h"
CPfCalcNode::CPfCalcNode()
{
	e = PF_CALC_DATA_INIT_VAL_SPEC;
	f = PF_CALC_DATA_INIT_VAL_SPEC;
	index =0;
}
CPfCalcNode::~CPfCalcNode()
{

}

CPfCalcNodeBl::CPfCalcNodeBl()
{
	Pl = PF_CALC_DATA_INIT_VAL_SPEC;//��֪��
	Ql = PF_CALC_DATA_INIT_VAL_SPEC;//��֪��
	Pg = PF_CALC_DATA_INIT_VAL_SPEC;//δ֪��
	Qg = PF_CALC_DATA_INIT_VAL_SPEC;//δ֪��
	offset=0;//Use for Jacorb Matrix and .deltaPQPU2[] and deltaEF[];
	offset2=0;//Use for .aii[] and .bii[]
}
CPfCalcNodeBl::~CPfCalcNodeBl()
{

}


CPfCalcNodePq::CPfCalcNodePq()
{
	P = PF_CALC_DATA_INIT_VAL_SPEC;//��֪��
	Q = PF_CALC_DATA_INIT_VAL_SPEC;//��֪��

	offset = 0;//Use for Jacorb Matrix and .deltaPQPU2[] and deltaEF[];
	offset2 = 0;//Use for .aii[] and .bii[]
}
CPfCalcNodePq::~CPfCalcNodePq()
{

}


CPfCalcNodePv::CPfCalcNodePv()
{
	P = PF_CALC_DATA_INIT_VAL_SPEC;//��֪��
	Ql = PF_CALC_DATA_INIT_VAL_SPEC;//��֪��
	Qg = PF_CALC_DATA_INIT_VAL_SPEC;//δ֪��
	U2 = PF_CALC_DATA_INIT_VAL_SPEC;//��֪��
	 offset=0;//Use for Jacorb Matrix and .deltaPQPU2[] and deltaEF[];
		offset2=0;//Use for .aii[] and .bii[]
}
CPfCalcNodePv::~CPfCalcNodePv()
{

}