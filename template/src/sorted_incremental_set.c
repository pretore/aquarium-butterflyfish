#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \\
    (*(struct butterflyfish_sorted_incremental_set_$t$ **) x)
#define INVOKE_INCREMENTAL_SET(x) \\
    (*(struct butterflyfish_incremental_set_$t$ **) x)
#define INVOKE_SORTED_SET(x)    (*(struct butterflyfish_sorted_set_$t$ **) x)
#define INVOKE_SORTED(x)        (*(struct butterflyfish_sorted_$t$ **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_$t$ **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_$t$ **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_$t$ **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_$t$ **) x)

static inline int
as_incremental_set(struct butterflyfish_sorted_incremental_set_$t$ *const object,
                   struct butterflyfish_incremental_set_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_incremental_set(object, out);
}

static inline int
as_sorted_set(const struct butterflyfish_sorted_incremental_set_$t$ *const object,
              const struct butterflyfish_sorted_set_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_sorted_set(object, out);
}

static inline int
as_sorted(const struct butterflyfish_sorted_incremental_set_$t$ *const object,
          const struct butterflyfish_sorted_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_sorted_set_$t$ *sorted_set;
    seagrass_required_true(!as_sorted_set(object, &sorted_set));
    return INVOKE_SORTED_SET(sorted_set)->as_sorted(sorted_set, out);
}

static inline int
as_set(const struct butterflyfish_sorted_incremental_set_$t$ *const object,
       const struct butterflyfish_set_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_set_$t$ *incremental_set;
    seagrass_required_true(!as_incremental_set(
            (void *) object, &incremental_set));
    return INVOKE_INCREMENTAL_SET(incremental_set)
            ->as_set(incremental_set, out);
}

static inline int
as_addable(struct butterflyfish_sorted_incremental_set_$t$ *const object,
           struct butterflyfish_addable_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_set_$t$ *incremental_set;
    seagrass_required_true(!as_incremental_set(
            (void *) object, &incremental_set));
    return INVOKE_INCREMENTAL_SET(incremental_set)
            ->as_addable(incremental_set, out);
}

static inline int
as_collection(const struct butterflyfish_sorted_incremental_set_$t$ *const object,
              const struct butterflyfish_collection_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(const struct butterflyfish_sorted_incremental_set_$t$ *const object,
          const struct butterflyfish_stream_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_$t$ -

int butterflyfish_sorted_incremental_set_$t$_first(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_sorted_incremental_set_$t$_next(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_$t$ -

int butterflyfish_sorted_incremental_set_$t$_count(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_sorted_incremental_set_$t$_last(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_sorted_incremental_set_$t$_prev(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark sorted_$t$ -

int butterflyfish_sorted_incremental_set_$t$_ceiling(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_$t$ *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->ceiling(sorted, value, out);
}

int butterflyfish_sorted_incremental_set_$t$_floor(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_$t$ *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->floor(sorted, value, out);
}

int butterflyfish_sorted_incremental_set_$t$_higher(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_$t$ *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->higher(sorted, value, out);
}

int butterflyfish_sorted_incremental_set_$t$_lower(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_$t$ *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->lower(sorted, value, out);
}

#pragma mark set_$t$ -

int butterflyfish_sorted_incremental_set_$t$_contains(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, value, out);
}

int butterflyfish_sorted_incremental_set_$t$_contains_all(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_sorted_incremental_set_$t$_get(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, value, out);
}

#pragma mark addable_$t$ -

int butterflyfish_sorted_incremental_set_$t$_add(
        struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const $v$const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_addable_$t$ *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, value);
}

int butterflyfish_sorted_incremental_set_$t$_add_all(
        struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_$t$ *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark sorted_incremental_set_$t$ -

int butterflyfish_sorted_incremental_set_$t$_as_stream(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const struct butterflyfish_stream_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_sorted_incremental_set_$t$_as_collection(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_sorted_incremental_set_$t$_as_addable(
        struct butterflyfish_sorted_incremental_set_$t$ *const object,
        struct butterflyfish_addable_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_sorted_incremental_set_$t$_as_sorted(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const struct butterflyfish_sorted_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_sorted(object, out);
}

int butterflyfish_sorted_incremental_set_$t$_as_set(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const struct butterflyfish_set_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_sorted_incremental_set_$t$_as_incremental_set(
        struct butterflyfish_sorted_incremental_set_$t$ *const object,
        struct butterflyfish_incremental_set_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_incremental_set(object, out);
}

int butterflyfish_sorted_incremental_set_$t$_as_sorted_set(
        const struct butterflyfish_sorted_incremental_set_$t$ *const object,
        const struct butterflyfish_sorted_set_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_sorted_set(object, out);
}
