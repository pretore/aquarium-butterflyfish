#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)               (*(struct butterflyfish_reducible_set_$t$ **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_$t$ **) x)
#define INVOKE_REMOVABLE(x)     (*(struct butterflyfish_removable_$t$ **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_$t$ **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_$t$ **) x)

static inline int
as_set(const struct butterflyfish_reducible_set_$t$ *const object,
       const struct butterflyfish_set_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_set(object, out);
}

static inline int
as_removable(struct butterflyfish_reducible_set_$t$ *const object,
             struct butterflyfish_removable_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_removable(object, out);
}

static inline int
as_collection(const struct butterflyfish_reducible_set_$t$ *const object,
              const struct butterflyfish_collection_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(const struct butterflyfish_reducible_set_$t$ *const object,
          const struct butterflyfish_stream_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_$t$ -

int butterflyfish_reducible_set_$t$_first(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_reducible_set_$t$_next(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_$t$ -

int butterflyfish_reducible_set_$t$_count(
        const struct butterflyfish_reducible_set_$t$ *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_reducible_set_$t$_last(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_reducible_set_$t$_prev(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark set_$t$ -

int butterflyfish_reducible_set_$t$_contains(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const $v$const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, value, out);
}

int butterflyfish_reducible_set_$t$_contains_all(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_reducible_set_$t$_get(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, value, out);
}

#pragma mark removable_$t$ -

int butterflyfish_reducible_set_$t$_remove_item(
        struct butterflyfish_reducible_set_$t$ *const object,
        const $v$const item) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    struct butterflyfish_removable_$t$ *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_item(removable, item);
}

int butterflyfish_reducible_set_$t$_remove_all_items(
        struct butterflyfish_reducible_set_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_removable_$t$ *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_all_items(removable, other);
}

#pragma mark reducible_set_$t$ -

int butterflyfish_reducible_set_$t$_as_stream(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const struct butterflyfish_stream_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_reducible_set_$t$_as_collection(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_reducible_set_$t$_as_set(
        const struct butterflyfish_reducible_set_$t$ *const object,
        const struct butterflyfish_set_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_reducible_set_$t$_as_removable(
        struct butterflyfish_reducible_set_$t$ *const object,
        struct butterflyfish_removable_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_removable(object, out);
}

int butterflyfish_reducible_set_$t$_remove(
        struct butterflyfish_reducible_set_$t$ *const object,
        const $v$const value) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    return INVOKE(object)->remove(object, value);
}

int butterflyfish_reducible_set_$t$_remove_all(
        struct butterflyfish_reducible_set_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL;
    }
    return INVOKE(object)->remove_all(object, other);
}

int butterflyfish_reducible_set_$t$_retain_all(
        struct butterflyfish_reducible_set_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL;
    }
    return INVOKE(object)->retain_all(object, other);
}
