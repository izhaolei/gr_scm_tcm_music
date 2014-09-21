#ifndef _SPECEST_SCTTCM_VCF_H
#define _SPECEST_SCTTCM_VCF_H

#include<specest_api.h>
#include<gr_sync_block.h>
#include<specest_scmtcm_impl.h>

class specest_scmtcm_vcf;
typedef boost::shared_ptr<specest_scmtcm_vcf> specest_scmtcm_vcf_sptr;

SPECEST_API specest_scmtcm_vcf_sptr specest_make_scmtcm_vcf(unsigned int n, unsigned int m, unsigned int nsamples);

class SPECEST_API specest_scmtcm_vcf: public gr_sync_block{
	public:
		~specest_scmtcm_vcf();
		int work(int noutput_items, gr_vector_const_void_star &input_items, gr_vector_void &output_items);

	private:
		friend SPECEST_API specest_scmtcm_vcf_sptr specest_make_scmtcm_vcf(unsigned int n, unsigned int m, unsigned int nsamples);
		specest_scmtcm_vcf(unsigned int n, unsigned int m, unsigned int nsamples);

		specest_scmtcm_impl* d_impl;
		unsigned int d_n, d_m, d_nsamples;
	
};

#endif
