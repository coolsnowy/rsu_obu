/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "DSRC_R36_Source.ASN"
 * 	`asn1c -S ../../../../tools/asn1c/skeletons -pdu=BasicSafetyMessage -fcompound-names`
 */

#ifndef	_ObstacleDirection_H_
#define	_ObstacleDirection_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Heading.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ObstacleDirection */
typedef Heading_t	 ObstacleDirection_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ObstacleDirection;
asn_struct_free_f ObstacleDirection_free;
asn_struct_print_f ObstacleDirection_print;
asn_constr_check_f ObstacleDirection_constraint;
ber_type_decoder_f ObstacleDirection_decode_ber;
der_type_encoder_f ObstacleDirection_encode_der;
xer_type_decoder_f ObstacleDirection_decode_xer;
xer_type_encoder_f ObstacleDirection_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _ObstacleDirection_H_ */
#include <asn_internal.h>
