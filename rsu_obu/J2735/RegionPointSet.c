/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "DSRC_R36_Source.ASN"
 * 	`asn1c -S ../../../../tools/asn1c/skeletons -pdu=BasicSafetyMessage -fcompound-names`
 */

#include "RegionPointSet.h"

static asn_TYPE_member_t asn_MBR_RegionPointSet_1[] = {
	{ ATF_POINTER, 1, offsetof(struct RegionPointSet, anchor),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position3D,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"anchor"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RegionPointSet, nodeList),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RegionList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"nodeList"
		},
};
static ber_tlv_tag_t asn_DEF_RegionPointSet_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_RegionPointSet_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* anchor at 1642 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* nodeList at 1643 */
};
static asn_SEQUENCE_specifics_t asn_SPC_RegionPointSet_specs_1 = {
	sizeof(struct RegionPointSet),
	offsetof(struct RegionPointSet, _asn_ctx),
	asn_MAP_RegionPointSet_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RegionPointSet = {
	"RegionPointSet",
	"RegionPointSet",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_RegionPointSet_tags_1,
	sizeof(asn_DEF_RegionPointSet_tags_1)
		/sizeof(asn_DEF_RegionPointSet_tags_1[0]), /* 1 */
	asn_DEF_RegionPointSet_tags_1,	/* Same as above */
	sizeof(asn_DEF_RegionPointSet_tags_1)
		/sizeof(asn_DEF_RegionPointSet_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RegionPointSet_1,
	2,	/* Elements count */
	&asn_SPC_RegionPointSet_specs_1	/* Additional specs */
};

