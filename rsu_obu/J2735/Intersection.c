/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "DSRC_R36_Source.ASN"
 * 	`asn1c -S ../../../../tools/asn1c/skeletons -pdu=BasicSafetyMessage -fcompound-names`
 */

#include "Intersection.h"

static int
memb_approaches_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 32)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_preemptZones_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 32)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_priorityZones_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 32)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_TYPE_member_t asn_MBR_approaches_9[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_ApproachObject,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_approaches_tags_9[] = {
	(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_approaches_specs_9 = {
	sizeof(struct Intersection__approaches),
	offsetof(struct Intersection__approaches, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_approaches_9 = {
	"approaches",
	"approaches",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_approaches_tags_9,
	sizeof(asn_DEF_approaches_tags_9)
		/sizeof(asn_DEF_approaches_tags_9[0]) - 1, /* 1 */
	asn_DEF_approaches_tags_9,	/* Same as above */
	sizeof(asn_DEF_approaches_tags_9)
		/sizeof(asn_DEF_approaches_tags_9[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_approaches_9,
	1,	/* Single element */
	&asn_SPC_approaches_specs_9	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_preemptZones_11[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_SignalControlZone,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_preemptZones_tags_11[] = {
	(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_preemptZones_specs_11 = {
	sizeof(struct Intersection__preemptZones),
	offsetof(struct Intersection__preemptZones, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_preemptZones_11 = {
	"preemptZones",
	"preemptZones",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_preemptZones_tags_11,
	sizeof(asn_DEF_preemptZones_tags_11)
		/sizeof(asn_DEF_preemptZones_tags_11[0]) - 1, /* 1 */
	asn_DEF_preemptZones_tags_11,	/* Same as above */
	sizeof(asn_DEF_preemptZones_tags_11)
		/sizeof(asn_DEF_preemptZones_tags_11[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_preemptZones_11,
	1,	/* Single element */
	&asn_SPC_preemptZones_specs_11	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_priorityZones_13[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_SignalControlZone,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_priorityZones_tags_13[] = {
	(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_priorityZones_specs_13 = {
	sizeof(struct Intersection__priorityZones),
	offsetof(struct Intersection__priorityZones, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_priorityZones_13 = {
	"priorityZones",
	"priorityZones",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_priorityZones_tags_13,
	sizeof(asn_DEF_priorityZones_tags_13)
		/sizeof(asn_DEF_priorityZones_tags_13[0]) - 1, /* 1 */
	asn_DEF_priorityZones_tags_13,	/* Same as above */
	sizeof(asn_DEF_priorityZones_tags_13)
		/sizeof(asn_DEF_priorityZones_tags_13[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_priorityZones_13,
	1,	/* Single element */
	&asn_SPC_priorityZones_specs_13	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Intersection_1[] = {
	{ ATF_POINTER, 1, offsetof(struct Intersection, name),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DescriptiveName,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"name"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Intersection, id),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IntersectionID,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"id"
		},
	{ ATF_POINTER, 5, offsetof(struct Intersection, refPoint),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position3D,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"refPoint"
		},
	{ ATF_POINTER, 4, offsetof(struct Intersection, refInterNum),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IntersectionID,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"refInterNum"
		},
	{ ATF_POINTER, 3, offsetof(struct Intersection, orientation),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Heading,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"orientation"
		},
	{ ATF_POINTER, 2, offsetof(struct Intersection, laneWidth),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LaneWidth,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"laneWidth"
		},
	{ ATF_POINTER, 1, offsetof(struct Intersection, type),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IntersectionStatusObject,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"type"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Intersection, approaches),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		0,
		&asn_DEF_approaches_9,
		memb_approaches_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"approaches"
		},
	{ ATF_POINTER, 2, offsetof(struct Intersection, preemptZones),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		0,
		&asn_DEF_preemptZones_11,
		memb_preemptZones_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"preemptZones"
		},
	{ ATF_POINTER, 1, offsetof(struct Intersection, priorityZones),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		0,
		&asn_DEF_priorityZones_13,
		memb_priorityZones_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"priorityZones"
		},
};
static ber_tlv_tag_t asn_DEF_Intersection_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_Intersection_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* name at 1076 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* id at 1077 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* refPoint at 1081 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* refInterNum at 1085 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* orientation at 1088 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* laneWidth at 1092 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* type at 1095 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* approaches at 1098 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* preemptZones at 1102 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 } /* priorityZones at 1106 */
};
static asn_SEQUENCE_specifics_t asn_SPC_Intersection_specs_1 = {
	sizeof(struct Intersection),
	offsetof(struct Intersection, _asn_ctx),
	asn_MAP_Intersection_tag2el_1,
	10,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	9,	/* Start extensions */
	11	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_Intersection = {
	"Intersection",
	"Intersection",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_Intersection_tags_1,
	sizeof(asn_DEF_Intersection_tags_1)
		/sizeof(asn_DEF_Intersection_tags_1[0]), /* 1 */
	asn_DEF_Intersection_tags_1,	/* Same as above */
	sizeof(asn_DEF_Intersection_tags_1)
		/sizeof(asn_DEF_Intersection_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Intersection_1,
	10,	/* Elements count */
	&asn_SPC_Intersection_specs_1	/* Additional specs */
};

