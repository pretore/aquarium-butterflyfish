#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)               (*(struct butterflyfish_sorted_list_$t$ **) x)
#define INVOKE_SORTED(x)        (*(struct butterflyfish_sorted_$t$ **) x)
#define INVOKE_LIST(x)          (*(struct butterflyfish_list_$t$ **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_$t$ **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_$t$ **) x)

static inline int
as_sorted(const struct butterflyfish_sorted_list_$t$ *const object,
          const struct butterflyfish_sorted_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_sorted(object, out);
}

static inline int
as_list(const struct butterflyfish_sorted_list_$t$ *const object,
        const struct butterflyfish_list_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_list(object, out);
}

static inline int
as_collection(const struct butterflyfish_sorted_list_$t$ *const object,
              const struct butterflyfish_collection_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_list_$t$ *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->as_collection(list, out);
}

static inline int
as_stream(const struct butterflyfish_sorted_list_$t$ *const object,
          const struct butterflyfish_stream_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_$t$ -

int butterflyfish_sorted_list_$t$_first(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_sorted_list_$t$_next(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_$t$ -

int butterflyfish_sorted_list_$t$_count(
        const struct butterflyfish_sorted_list_$t$ *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_sorted_list_$t$_last(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_sorted_list_$t$_prev(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark sorted_$t$ -

int butterflyfish_sorted_list_$t$_ceiling(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_$t$ *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->ceiling(sorted, value, out);
}

int butterflyfish_sorted_list_$t$_floor(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_$t$ *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->floor(sorted, value, out);
}

int butterflyfish_sorted_list_$t$_higher(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_$t$ *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->higher(sorted, value, out);
}

int butterflyfish_sorted_list_$t$_lower(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_$t$ *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->lower(sorted, value, out);
}

#pragma mark list_$t$ -

int butterflyfish_sorted_list_$t$_get(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const uintmax_t at,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_$t$ *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->get(list, at, out);
}

int butterflyfish_sorted_list_$t$_at(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const $v$const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_$t$ *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->at(list, item, out);
}

#pragma mark sorted_list_$t$ -

int butterflyfish_sorted_list_$t$_as_stream(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const struct butterflyfish_stream_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_sorted_list_$t$_as_collection(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_sorted_list_$t$_as_list(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const struct butterflyfish_list_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_list(object, out);
}

int butterflyfish_sorted_list_$t$_as_sorted(
        const struct butterflyfish_sorted_list_$t$ *const object,
        const struct butterflyfish_sorted_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_sorted(object, out);
}
