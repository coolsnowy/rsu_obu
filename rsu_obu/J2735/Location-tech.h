/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "DSRC_R36_Source.ASN"
 * 	`asn1c -S ../../../../tools/asn1c/skeletons -pdu=BasicSafetyMessage -fcompound-names`
 */

#ifndef	_Location_tech_H_
#define	_Location_tech_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Location_tech {
	Location_tech_loc_tech_unknown	= 0,
	Location_tech_loc_tech_GPS	= 1,
	Location_tech_loc_tech_DGPS	= 2,
	Location_tech_loc_tech_drGPS	= 3,
	Location_tech_loc_tech_drDGPS	= 4,
	Location_tech_loc_tech_dr	= 5,
	Location_tech_loc_tech_nav	= 6,
	/*
	 * Enumeration is extensible
	 */
	Location_tech_loc_tech_fault	= 31
} e_Location_tech;

/* Location-tech */
typedef long	 Location_tech_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Location_tech;
asn_struct_free_f Location_tech_free;
asn_struct_print_f Location_tech_print;
asn_constr_check_f Location_tech_constraint;
ber_type_decoder_f Location_tech_decode_ber;
der_type_encoder_f Location_tech_encode_der;
xer_type_decoder_f Location_tech_decode_xer;
xer_type_encoder_f Location_tech_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Location_tech_H_ */
#include <asn_internal.h>
