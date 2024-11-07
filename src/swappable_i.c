#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)               (*(struct butterflyfish_swappable_i **) x)
#define INVOKE_ORDERED(x)       (*(struct butterflyfish_ordered_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i **) x)

static inline int
as_ordered(const struct butterflyfish_swappable_i *const object,
           const struct butterflyfish_ordered_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_ordered(object, out);
}

static inline int
as_collection(const struct butterflyfish_swappable_i *const object,
              const struct butterflyfish_collection_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_ordered_i *ordered;
    seagrass_required_true(!as_ordered(object, &ordered));
    return INVOKE_ORDERED(ordered)->as_collection(ordered, out);
}

static inline int
as_stream(const struct butterflyfish_swappable_i *const object,
          const struct butterflyfish_stream_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i -

int butterflyfish_swappable_i_first(
        const struct butterflyfish_swappable_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_swappable_i_next(
        const struct butterflyfish_swappable_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i -

int butterflyfish_swappable_i_count(
        const struct butterflyfish_swappable_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_swappable_i_last(
        const struct butterflyfish_swappable_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_swappable_i_prev(
        const struct butterflyfish_swappable_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark ordered -

#pragma mark swappable -

int butterflyfish_swappable_i_as_stream(
        const struct butterflyfish_swappable_i *const object,
        const struct butterflyfish_stream_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_swappable_i_as_collection(
        const struct butterflyfish_swappable_i *const object,
        const struct butterflyfish_collection_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_swappable_i_as_ordered(
        const struct butterflyfish_swappable_i *const object,
        const struct butterflyfish_ordered_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered(object, out);
}

int butterflyfish_swappable_i_swap(
        struct butterflyfish_swappable_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer *const other) {
    if (!object) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_ITEM_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SWAPPABLE_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKE(object)->swap(object, item, other);
}
