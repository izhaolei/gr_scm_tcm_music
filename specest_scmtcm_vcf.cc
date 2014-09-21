#ifdef HAVE_CONFIG_H
#include"config.h"
#endif

#include<gr_io_signature.h>
#include<specest_scttec_vcf.h>
#include<specest_scmtcm_armadillo_impl.h>

specest_scmtcm_vcf_sptr specest_make_scmtcm_vcf(unsigned int n, unsigned int m, unsigned int nsamples){
	return specest_scmtcm_vcf_sptr(new specest_scmtcm_vcf(n, m, nsamples));
}

specest_scmtcm_vcf::specest_scmtcm_vcf(unsigned int n, unsigned int m, unsigned int nsamples):
	gr_sync_block("scmtcm_vcf",
			gr_make_io_signature(2, 2, nsamples * sizeof(gr_complex)),
			gr_make_io_signature(1, 1, n * sizeof(float))),
	d_m(m),
	d_n(n),
	d_nsamples(nsamples),
	//TODO: TO PASS ARGS TO THE CONSTRCTOR
	d_impl(new specest_scmtcm_armadillo_impl()){
}

specest_scmtcm_vcf::~specest_scmtcm_vcf(){
	delete d_impl;
}

int specest_scmtcm_vcf::work(int noutput_items,
							gr_vector_const_void_star &input_items,
							gr_vector_void_star &output_items){
	const gr_complex *in = static_cast<const gr_complex *>(input_items[0]);
	gr_complexd *tmpin = static_cast<gr_complexd>(in[i]);
	float *out = static_cast<float *>(output_items[0]);
	double *tmpout = new double[d_n];
	d_impl->calculate(tmpin, d_nsamples, tmpout);

	for(int i = 0; i < d_n; i++){
		out[i] = float(tmpout[i]);
	}

	delete[] tmpout;
	delete[] tmpin;

	return noutput_items;
}
