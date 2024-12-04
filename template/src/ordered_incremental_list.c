#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \\
    (*(struct butterflyfish_ordered_incremental_list_$t$ **) x)
#define INVOKE_ORDERED_LIST(x)  (*(struct butterflyfish_ordered_list_$t$ **) x)
#define INVOKE_INCREMENTAL_LIST(x) \\
    (*(struct butterflyfish_incremental_list_$t$ **) x)
#define INVOKE_LIST(x)          (*(struct butterflyfish_list_$t$ **) x)
#define INVOKE_INSERTABLE(x)    (*(struct butterflyfish_insertable_$t$ **) x)
#define INVOKE_ORDERED(x)       (*(struct butterflyfish_ordered_$t$ **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_$t$ **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_$t$ **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_$t$ **) x)

static inline int
as_insertable(
        struct butterflyfish_ordered_incremental_list_$t$ *const object,
        struct butterflyfish_insertable_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_insertable(object, out);
}

static inline int
as_ordered_list(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const struct butterflyfish_ordered_list_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_ordered_list(object, out);
}

static inline int
as_incremental_list(
        struct butterflyfish_ordered_incremental_list_$t$ *const object,
        struct butterflyfish_incremental_list_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_incremental_list(object, out);
}

static inline int
as_list(const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const struct butterflyfish_list_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_list_$t$ *incremental_list;
    seagrass_required_true(!as_incremental_list((void *) object,
            &incremental_list));
    return INVOKE_INCREMENTAL_LIST(incremental_list)
            ->as_list(incremental_list, out);
}

static inline int
as_ordered(const struct butterflyfish_ordered_incremental_list_$t$ *const object,
           const struct butterflyfish_ordered_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_ordered_list_$t$ *ordered_list;
    seagrass_required_true(!as_ordered_list(object, &ordered_list));
    return INVOKE_ORDERED_LIST(ordered_list)->as_ordered(ordered_list, out);
}

static inline int
as_addable(struct butterflyfish_ordered_incremental_list_$t$ *const object,
           struct butterflyfish_addable_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_list_$t$ *incremental_list;
    seagrass_required_true(!as_incremental_list(object, &incremental_list));
    return INVOKE_INCREMENTAL_LIST(incremental_list)
            ->as_addable(incremental_list, out);
}

static inline int
as_collection(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_list_$t$ *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->as_collection(list, out);
}

static inline int
as_stream(const struct butterflyfish_ordered_incremental_list_$t$ *const object,
          const struct butterflyfish_stream_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_$t$ -

int butterflyfish_ordered_incremental_list_$t$_first(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_ordered_incremental_list_$t$_next(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_$t$ -

int butterflyfish_ordered_incremental_list_$t$_count(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_ordered_incremental_list_$t$_last(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_ordered_incremental_list_$t$_prev(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark list_$t$ -

int butterflyfish_ordered_incremental_list_$t$_get(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const uintmax_t at,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_$t$ *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->get(list, at, out);
}

int butterflyfish_ordered_incremental_list_$t$_at(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const $v$const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_$t$ *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->at(list, item, out);
}

#pragma mark addable_$t$ -

int butterflyfish_ordered_incremental_list_$t$_add(
        struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const $v$const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_addable_$t$ *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, value);
}

int butterflyfish_ordered_incremental_list_$t$_add_all(
        struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_$t$ *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark insertable_$t$ -

int butterflyfish_ordered_incremental_list_$t$_insert(
        struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const $v$const item,
        const $v$const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_insertable_$t$ *insertable;
    seagrass_required_true(!as_insertable(object, &insertable));
    return INVOKE_INSERTABLE(insertable)->insert(insertable, item, value);
}

int butterflyfish_ordered_incremental_list_$t$_insert_all(
        struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const $v$const item,
        const struct butterflyfish_stream_$t$ *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_insertable_$t$ *insertable;
    seagrass_required_true(!as_insertable(object, &insertable));
    return INVOKE_INSERTABLE(insertable)->insert_all(insertable, item, other);
}

#pragma mark ordered_incremental_list_$t$ -

int butterflyfish_ordered_incremental_list_$t$_as_stream(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const struct butterflyfish_stream_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_ordered_incremental_list_$t$_as_collection(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_ordered_incremental_list_$t$_as_ordered(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const struct butterflyfish_ordered_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_ordered(object, out);
}

int butterflyfish_ordered_incremental_list_$t$_as_insertable(
        struct butterflyfish_ordered_incremental_list_$t$ *const object,
        struct butterflyfish_insertable_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_insertable(object, out);
}

int butterflyfish_ordered_incremental_list_$t$_as_addable(
        struct butterflyfish_ordered_incremental_list_$t$ *const object,
        struct butterflyfish_addable_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_ordered_incremental_list_$t$_as_list(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const struct butterflyfish_list_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_list(object, out);
}

int butterflyfish_ordered_incremental_list_$t$_as_incremental_list(
        struct butterflyfish_ordered_incremental_list_$t$ *const object,
        struct butterflyfish_incremental_list_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_incremental_list(object, out);
}

int butterflyfish_ordered_incremental_list_$t$_as_ordered_list(
        const struct butterflyfish_ordered_incremental_list_$t$ *const object,
        const struct butterflyfish_ordered_list_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL;
    }
    return as_ordered_list(object, out);
}
