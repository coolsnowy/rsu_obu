/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "DSRC_R36_Source.ASN"
 * 	`asn1c -S ../../../../tools/asn1c/skeletons -pdu=BasicSafetyMessage -fcompound-names`
 */

#ifndef	_WiperStatusFront_H_
#define	_WiperStatusFront_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum WiperStatusFront {
	WiperStatusFront_unavailable	= 0,
	WiperStatusFront_off	= 1,
	WiperStatusFront_intermittent	= 2,
	WiperStatusFront_low	= 3,
	WiperStatusFront_high	= 4,
	WiperStatusFront_washerInUse	= 126,
	WiperStatusFront_automaticPresent	= 127
	/*
	 * Enumeration is extensible
	 */
} e_WiperStatusFront;

/* WiperStatusFront */
typedef long	 WiperStatusFront_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WiperStatusFront;
asn_struct_free_f WiperStatusFront_free;
asn_struct_print_f WiperStatusFront_print;
asn_constr_check_f WiperStatusFront_constraint;
ber_type_decoder_f WiperStatusFront_decode_ber;
der_type_encoder_f WiperStatusFront_encode_der;
xer_type_decoder_f WiperStatusFront_decode_xer;
xer_type_encoder_f WiperStatusFront_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _WiperStatusFront_H_ */
#include <asn_internal.h>
