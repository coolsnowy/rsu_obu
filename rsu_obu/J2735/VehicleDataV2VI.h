/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "DSRC_R36_Source.ASN"
 * 	`asn1c -S ../../../../tools/asn1c/skeletons -pdu=BasicSafetyMessage -fcompound-names`
 */

#ifndef	_VehicleDataV2VI_H_
#define	_VehicleDataV2VI_H_


#include <asn_application.h>

/* Including external dependencies */
#include "VehicleHeight.h"
#include "VehicleMass.h"
#include "TrailerWeight.h"
#include "VehicleType.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BumperHeights;

/* VehicleDataV2VI */
typedef struct VehicleDataV2VI {
	VehicleHeight_t	*height	/* OPTIONAL */;
	struct BumperHeights	*bumpers	/* OPTIONAL */;
	VehicleMass_t	*mass	/* OPTIONAL */;
	TrailerWeight_t	*trailerWeight	/* OPTIONAL */;
	VehicleType_t	*type	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VehicleDataV2VI_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_VehicleDataV2VI;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BumperHeights.h"

#endif	/* _VehicleDataV2VI_H_ */
#include <asn_internal.h>
