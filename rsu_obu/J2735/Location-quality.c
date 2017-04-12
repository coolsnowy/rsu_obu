/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "DSRC_R36_Source.ASN"
 * 	`asn1c -S ../../../../tools/asn1c/skeletons -pdu=BasicSafetyMessage -fcompound-names`
 */

#include "Location-quality.h"

int
Location_quality_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
Location_quality_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

void
Location_quality_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	Location_quality_1_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

int
Location_quality_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	Location_quality_1_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
Location_quality_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	Location_quality_1_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
Location_quality_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	Location_quality_1_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
Location_quality_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	Location_quality_1_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
Location_quality_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	Location_quality_1_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_INTEGER_enum_map_t asn_MAP_Location_quality_value2enum_1[] = {
	{ 0,	13,	"loc-qual-bt1m" },
	{ 1,	13,	"loc-qual-bt5m" },
	{ 2,	14,	"loc-qual-bt12m" },
	{ 3,	14,	"loc-qual-bt50m" },
	{ 4,	15,	"loc-qual-bt125m" },
	{ 5,	15,	"loc-qual-bt500m" },
	{ 6,	16,	"loc-qual-bt1250m" },
	{ 7,	16,	"loc-qual-unknown" }
};
static unsigned int asn_MAP_Location_quality_enum2value_1[] = {
	6,	/* loc-qual-bt1250m(6) */
	4,	/* loc-qual-bt125m(4) */
	2,	/* loc-qual-bt12m(2) */
	0,	/* loc-qual-bt1m(0) */
	5,	/* loc-qual-bt500m(5) */
	3,	/* loc-qual-bt50m(3) */
	1,	/* loc-qual-bt5m(1) */
	7	/* loc-qual-unknown(7) */
};
static asn_INTEGER_specifics_t asn_SPC_Location_quality_specs_1 = {
	asn_MAP_Location_quality_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_Location_quality_enum2value_1,	/* N => "tag"; sorted by N */
	8,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_Location_quality_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_Location_quality = {
	"Location-quality",
	"Location-quality",
	Location_quality_free,
	Location_quality_print,
	Location_quality_constraint,
	Location_quality_decode_ber,
	Location_quality_encode_der,
	Location_quality_decode_xer,
	Location_quality_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_Location_quality_tags_1,
	sizeof(asn_DEF_Location_quality_tags_1)
		/sizeof(asn_DEF_Location_quality_tags_1[0]), /* 1 */
	asn_DEF_Location_quality_tags_1,	/* Same as above */
	sizeof(asn_DEF_Location_quality_tags_1)
		/sizeof(asn_DEF_Location_quality_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	0, 0,	/* Defined elsewhere */
	&asn_SPC_Location_quality_specs_1	/* Additional specs */
};

