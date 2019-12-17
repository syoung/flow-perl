/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.40 from the
 * contents of Util.xs. Do not edit this file, edit Util.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Util.xs"
#define PERL_NO_GET_CONTEXT

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#line 17 "Util.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
	    Perl_croak_nocontext("Usage: %s::%s(%s)", hvname, gvname, params);
        else
	    Perl_croak_nocontext("Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
	Perl_croak_nocontext("Usage: CODE(0x%" UVxf ")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#define croak_xs_usage        S_croak_xs_usage

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#if PERL_VERSION_LE(5, 21, 5)
#  define newXS_deffile(a,b) Perl_newXS(aTHX_ a,b,file)
#else
#  define newXS_deffile(a,b) Perl_newXS_deffile(aTHX_ a,b)
#endif

#line 161 "Util.c"

XS_EUPXS(XS_Hash__Util__clear_placeholders); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util__clear_placeholders)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "hashref");
    {
	HV *	hashref;
#line 14 "Util.xs"
        HV *hv;
#line 173 "Util.c"

	STMT_START {
		SV* const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVHV){
		    hashref = (HV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak_nocontext("%s: %s is not a HASH reference",
				"Hash::Util::_clear_placeholders",
				"hashref");
		}
	} STMT_END
;
#line 16 "Util.xs"
        hv = MUTABLE_HV(hashref);
        hv_clear_placeholders(hv);
#line 191 "Util.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Hash__Util_all_keys); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_all_keys)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "hash, keys, placeholder");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	HV *	hash;
	AV *	keys;
	AV *	placeholder;
#line 26 "Util.xs"
        SV *key;
        HE *he;
#line 212 "Util.c"

	STMT_START {
		SV* const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVHV){
		    hash = (HV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak_nocontext("%s: %s is not a HASH reference",
				"Hash::Util::all_keys",
				"hash");
		}
	} STMT_END
;

	STMT_START {
		SV* const xsub_tmp_sv = ST(1);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVAV){
		    keys = (AV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak_nocontext("%s: %s is not an ARRAY reference",
				"Hash::Util::all_keys",
				"keys");
		}
	} STMT_END
;

	STMT_START {
		SV* const xsub_tmp_sv = ST(2);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVAV){
		    placeholder = (AV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak_nocontext("%s: %s is not an ARRAY reference",
				"Hash::Util::all_keys",
				"placeholder");
		}
	} STMT_END
;
#line 29 "Util.xs"
        av_clear(keys);
        av_clear(placeholder);

        (void)hv_iterinit(hash);
	while((he = hv_iternext_flags(hash, HV_ITERNEXT_WANTPLACEHOLDERS))!= NULL) {
	    key=hv_iterkeysv(he);
	    av_push(HeVAL(he) == &PL_sv_placeholder ? placeholder : keys,
		    SvREFCNT_inc(key));
        }
	XSRETURN(1);
#line 266 "Util.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Hash__Util_hidden_ref_keys); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_hidden_ref_keys)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "hash");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	HV *	hash;
#line 46 "Util.xs"
        SV *key;
        HE *he;
#line 287 "Util.c"

	STMT_START {
		SV* const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVHV){
		    hash = (HV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak_nocontext("%s: %s is not a HASH reference",
				GvNAME(CvGV(cv)),
				"hash");
		}
	} STMT_END
;
#line 49 "Util.xs"
        (void)hv_iterinit(hash);
	while((he = hv_iternext_flags(hash, HV_ITERNEXT_WANTPLACEHOLDERS))!= NULL) {
	    key=hv_iterkeysv(he);
            if (ix || HeVAL(he) == &PL_sv_placeholder) {
                XPUSHs( key );
            }
        }
#line 310 "Util.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Hash__Util_hv_store); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_hv_store)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "hash, key, val");
    {
	HV *	hash;
	SV*	key = ST(1)
;
	SV*	val = ST(2)
;

	STMT_START {
		SV* const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVHV){
		    hash = (HV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak_nocontext("%s: %s is not a HASH reference",
				"Hash::Util::hv_store",
				"hash");
		}
	} STMT_END
;
#line 64 "Util.xs"
    {
        SvREFCNT_inc(val);
	if (!hv_store_ent(hash, key, val, 0)) {
	    SvREFCNT_dec(val);
	    XSRETURN_NO;
	} else {
	    XSRETURN_YES;
	}
    }
#line 353 "Util.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Hash__Util_hash_seed); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_hash_seed)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 78 "Util.xs"
    mXPUSHs(newSVpvn((char *)PERL_HASH_SEED,PERL_HASH_SEED_BYTES));
    XSRETURN(1);
#line 371 "Util.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Hash__Util_hash_value); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_hash_value)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "string, ...");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV*	string = ST(0)
;
#line 87 "Util.xs"
{
    UV uv;
    STRLEN len;
    char *pv= SvPV(string,len);
    if (items<2) {
        PERL_HASH(uv, pv, len);
    } else {
        STRLEN seedlen;
        U8 *seedbuf= (U8 *)SvPV(ST(1),seedlen);
        if ( seedlen < PERL_HASH_SEED_BYTES ) {
            sv_dump(ST(1));
            Perl_croak(aTHX_ "seed len must be at least %d long only got %"
                             UVuf " bytes", PERL_HASH_SEED_BYTES, (UV)seedlen);
        }

        PERL_HASH_WITH_SEED(seedbuf, uv, pv, len);
    }
    XSRETURN_UV(uv);
}
#line 409 "Util.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Hash__Util_hash_traversal_mask); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_hash_traversal_mask)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "rhv, ...");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV*	rhv = ST(0)
;
#line 111 "Util.xs"
{
#ifdef PERL_HASH_RANDOMIZE_KEYS
    if (SvROK(rhv) && SvTYPE(SvRV(rhv))==SVt_PVHV && !SvMAGICAL(SvRV(rhv))) {
        HV *hv = (HV *)SvRV(rhv);
        if (items>1) {
            hv_rand_set(hv, SvUV(ST(1)));
        }
        if (SvOOK(hv)) {
            XSRETURN_UV(HvRAND_get(hv));
        } else {
            XSRETURN_UNDEF;
        }
    }
#else
    Perl_croak(aTHX_ "Perl has not been compiled with support for randomized hash key traversal");
#endif
}
#line 445 "Util.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Hash__Util_bucket_info); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_bucket_info)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "rhv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV*	rhv = ST(0)
;
#line 133 "Util.xs"
{
    /*

    Takes a non-magical hash ref as an argument and returns a list of
    statistics about the hash. The number and keys and the size of the
    array will always be reported as the first two values. If the array is
    actually allocated (they are lazily allocated), then additionally
    will return a list of counts of bucket lengths. In other words in

        ($keys, $buckets, $used, @length_count)= hash::bucket_info(\%hash);

    $length_count[0] is the number of empty buckets, and $length_count[1]
    is the number of buckets with only one key in it, $buckets - $length_count[0]
    gives the number of used buckets, and @length_count-1 is the maximum
    bucket depth.

    If the argument is not a hash ref, or if it is magical, then returns
    nothing (the empty list).

    */
    const HV * hv = NULL;
    if (SvROK(rhv) && SvTYPE(SvRV(rhv))==SVt_PVHV && !SvMAGICAL(SvRV(rhv))) {
        hv = (const HV *) SvRV(rhv);
    } else if (!SvOK(rhv)) {
        hv = PL_strtab;
    }
    if (hv) {
        U32 max_bucket_index= HvMAX(hv);
        U32 total_keys= HvUSEDKEYS(hv);
        HE **bucket_array= HvARRAY(hv);
        mXPUSHi(total_keys);
        mXPUSHi(max_bucket_index+1);
        mXPUSHi(0); /* for the number of used buckets */
#define BUCKET_INFO_ITEMS_ON_STACK 3
        if (!bucket_array) {
            XSRETURN(BUCKET_INFO_ITEMS_ON_STACK);
        } else {
            /* we use chain_length to index the stack - we eliminate an add
             * by initializing things with the number of items already on the stack.
             * If we have 2 items then ST(2+0) (the third stack item) will be the counter
             * for empty chains, ST(2+1) will be for chains with one element,  etc.
             */
            I32 max_chain_length= BUCKET_INFO_ITEMS_ON_STACK - 1; /* so we do not have to do an extra push for the 0 index */
            HE *he;
            U32 bucket_index;
            for ( bucket_index= 0; bucket_index <= max_bucket_index; bucket_index++ ) {
                I32 chain_length= BUCKET_INFO_ITEMS_ON_STACK;
                for (he= bucket_array[bucket_index]; he; he= HeNEXT(he) ) {
                    chain_length++;
                }
                while ( max_chain_length < chain_length ) {
                    mXPUSHi(0);
                    max_chain_length++;
                }
                SvIVX( ST( chain_length ) )++;
            }
            /* now set the number of used buckets */
            SvIVX( ST( BUCKET_INFO_ITEMS_ON_STACK - 1 ) ) = max_bucket_index - SvIVX( ST( BUCKET_INFO_ITEMS_ON_STACK ) ) + 1;
            XSRETURN( max_chain_length + 1 ); /* max_chain_length is the index of the last item on the stack, so we add 1 */
        }
#undef BUCKET_INFO_ITEMS_ON_STACK
    }
    XSRETURN(0);
}
#line 528 "Util.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Hash__Util_bucket_array); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_bucket_array)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "rhv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV*	rhv = ST(0)
;
#line 202 "Util.xs"
{
    /* Returns an array of arrays representing key/bucket mappings.
     * Each element of the array contains either an integer or a reference
     * to an array of keys. A plain integer represents K empty buckets. An
     * array ref represents a single bucket, with each element being a key in
     * the hash. (Note this treats a placeholder as a normal key.)
     *
     * This allows one to "see" the keyorder. Note the "insert first" nature
     * of the hash store, combined with regular remappings means that relative
     * order of keys changes each remap.
     */
    const HV * hv = NULL;
    if (SvROK(rhv) && SvTYPE(SvRV(rhv))==SVt_PVHV && !SvMAGICAL(SvRV(rhv))) {
        hv = (const HV *) SvRV(rhv);
    } else if (!SvOK(rhv)) {
        hv = PL_strtab;
    }
    if (hv) {
        HE **he_ptr= HvARRAY(hv);
        if (!he_ptr) {
            XSRETURN(0);
        } else {
            U32 i, max;
            AV *info_av;
            HE *he;
            I32 empty_count=0;
            if (SvMAGICAL(hv)) {
                Perl_croak(aTHX_ "hash::bucket_array only works on 'normal' hashes");
            }
            info_av= newAV();
            max= HvMAX(hv);
            mXPUSHs(newRV_noinc((SV*)info_av));
            for ( i= 0; i <= max; i++ ) {
                AV *key_av= NULL;
                for (he= he_ptr[i]; he; he= HeNEXT(he) ) {
                    SV *key_sv;
                    char *str;
                    STRLEN len;
                    char mode;
                    if (!key_av) {
                        key_av= newAV();
                        if (empty_count) {
                            av_push(info_av, newSViv(empty_count));
                            empty_count= 0;
                        }
                        av_push(info_av, (SV *)newRV_noinc((SV *)key_av));
                    }
                    if (HeKLEN(he) == HEf_SVKEY) {
                        SV *sv= HeSVKEY(he);
                        SvGETMAGIC(sv);
                        str= SvPV(sv, len);
                        mode= SvUTF8(sv) ? 1 : 0;
                    } else {
                        str= HeKEY(he);
                        len= HeKLEN(he);
                        mode= HeKUTF8(he) ? 1 : 0;
                    }
                    key_sv= newSVpvn(str,len);
                    av_push(key_av,key_sv);
                    if (mode) {
                        SvUTF8_on(key_sv);
                    }
                }
                if (!key_av)
                    empty_count++;
            }
            if (empty_count) {
                av_push(info_av, newSViv(empty_count));
                empty_count++;
            }
        }
        XSRETURN(1);
    }
    XSRETURN(0);
}
#line 622 "Util.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Hash__Util_bucket_ratio); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_bucket_ratio)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "rhv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV*	rhv = ST(0)
;
#line 283 "Util.xs"
{
    if (SvROK(rhv)) {
        rhv= SvRV(rhv);
        if ( SvTYPE(rhv)==SVt_PVHV ) {
#if PERL_VERSION < 25
            SV *ret= Perl_hv_scalar(aTHX_ (HV*)rhv);
#else
            SV *ret= Perl_hv_bucket_ratio(aTHX_ (HV*)rhv);
#endif
            ST(0)= ret;
            XSRETURN(1);
        }
    }
    XSRETURN_UNDEF;
}
#line 656 "Util.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Hash__Util_num_buckets); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_num_buckets)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "rhv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV*	rhv = ST(0)
;
#line 304 "Util.xs"
{
    if (SvROK(rhv)) {
        rhv= SvRV(rhv);
        if ( SvTYPE(rhv)==SVt_PVHV ) {
            XSRETURN_UV(HvMAX((HV*)rhv)+1);
        }
    }
    XSRETURN_UNDEF;
}
#line 684 "Util.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Hash__Util_used_buckets); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Hash__Util_used_buckets)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "rhv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV*	rhv = ST(0)
;
#line 319 "Util.xs"
{
    if (SvROK(rhv)) {
        rhv= SvRV(rhv);
        if ( SvTYPE(rhv)==SVt_PVHV ) {
            XSRETURN_UV(HvFILL((HV*)rhv));
        }
    }
    XSRETURN_UNDEF;
}
#line 712 "Util.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Hash__Util); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Hash__Util)
{
#if PERL_VERSION_LE(5, 21, 5)
    dVAR; dXSARGS;
#else
    dVAR; dXSBOOTARGSXSAPIVERCHK;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(file);

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#if PERL_VERSION_LE(5, 21, 5)
    XS_VERSION_BOOTCHECK;
#  ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#  endif
#endif

        (void)newXSproto_portable("Hash::Util::_clear_placeholders", XS_Hash__Util__clear_placeholders, file, "\\%");
        (void)newXSproto_portable("Hash::Util::all_keys", XS_Hash__Util_all_keys, file, "\\%\\@\\@");
        cv = newXS_deffile("Hash::Util::hidden_ref_keys", XS_Hash__Util_hidden_ref_keys);
        XSANY.any_i32 = 0;
        cv = newXS_deffile("Hash::Util::legal_ref_keys", XS_Hash__Util_hidden_ref_keys);
        XSANY.any_i32 = 1;
        (void)newXSproto_portable("Hash::Util::hv_store", XS_Hash__Util_hv_store, file, "\\%$$");
        (void)newXSproto_portable("Hash::Util::hash_seed", XS_Hash__Util_hash_seed, file, "");
        (void)newXSproto_portable("Hash::Util::hash_value", XS_Hash__Util_hash_value, file, "$;$");
        newXS_deffile("Hash::Util::hash_traversal_mask", XS_Hash__Util_hash_traversal_mask);
        newXS_deffile("Hash::Util::bucket_info", XS_Hash__Util_bucket_info);
        newXS_deffile("Hash::Util::bucket_array", XS_Hash__Util_bucket_array);
        (void)newXSproto_portable("Hash::Util::bucket_ratio", XS_Hash__Util_bucket_ratio, file, "\\%");
        (void)newXSproto_portable("Hash::Util::num_buckets", XS_Hash__Util_num_buckets, file, "\\%");
        (void)newXSproto_portable("Hash::Util::used_buckets", XS_Hash__Util_used_buckets, file, "\\%");
#if PERL_VERSION_LE(5, 21, 5)
#  if PERL_VERSION_GE(5, 9, 0)
    if (PL_unitcheckav)
        call_list(PL_scopestack_ix, PL_unitcheckav);
#  endif
    XSRETURN_YES;
#else
    Perl_xs_boot_epilog(aTHX_ ax);
#endif
}

