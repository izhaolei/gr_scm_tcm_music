#ifndef _SPECEST_SCTTCM_IMPL_H
#define _SPECEST_SCTTCM_IMPL_H

#include<gr_complex.h>
#include<specest_api.h>

class SPECEST_API specest_scmtcm_impl{
	public:
		virtual void calculate(const gr_complexd *data, unsigned int data_len, double *angle);
}

#endif
