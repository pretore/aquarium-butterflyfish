#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)               (*(struct butterflyfish_set_i_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i_i **) x)

static inline int
as_collection(const struct butterflyfish_set_i_i *const object,
              const struct butterflyfish_collection_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_collection(object, out);
}

static inline int
as_stream(const struct butterflyfish_set_i_i *const object,
          const struct butterflyfish_stream_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i_i -

int butterflyfish_set_i_i_first(
        const struct butterflyfish_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_set_i_i_next(
        const struct butterflyfish_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i_i -

int butterflyfish_set_i_i_count(
        const struct butterflyfish_set_i_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_set_i_i_last(
        const struct butterflyfish_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_set_i_i_prev(
        const struct butterflyfish_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark set_i_i -

int butterflyfish_set_i_i_as_stream(
        const struct butterflyfish_set_i_i *const object,
        const struct butterflyfish_stream_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_set_i_i_as_collection(
        const struct butterflyfish_set_i_i *const object,
        const struct butterflyfish_collection_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_set_i_i_contains(
        const struct butterflyfish_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->contains(object, value, out);
}

int butterflyfish_set_i_i_contains_all(
        const struct butterflyfish_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->contains_all(object, other, out);
}

int butterflyfish_set_i_i_get(
        const struct butterflyfish_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->get(object, value, out);
}


