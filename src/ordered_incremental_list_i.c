#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \
    (*(struct butterflyfish_ordered_incremental_list_i **) x)
#define INVOKE_ORDERED_LIST(x)  (*(struct butterflyfish_ordered_list_i **) x)
#define INVOKE_INCREMENTAL_LIST(x) \
    (*(struct butterflyfish_incremental_list_i **) x)
#define INVOKE_LIST(x)          (*(struct butterflyfish_list_i **) x)
#define INVOKE_INSERTABLE(x)    (*(struct butterflyfish_insertable_i **) x)
#define INVOKE_ORDERED(x)       (*(struct butterflyfish_ordered_i **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i **) x)

static inline int
as_insertable(
        struct butterflyfish_ordered_incremental_list_i *const object,
        struct butterflyfish_insertable_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_insertable(object, out);
}

static inline int
as_ordered_list(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_ordered_list_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_ordered_list(object, out);
}

static inline int
as_incremental_list(
        struct butterflyfish_ordered_incremental_list_i *const object,
        struct butterflyfish_incremental_list_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_incremental_list(object, out);
}

static inline int
as_list(const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_list_i *incremental_list;
    seagrass_required_true(!as_incremental_list((void *) object,
            &incremental_list));
    return INVOKE_INCREMENTAL_LIST(incremental_list)
            ->as_list(incremental_list, out);
}

static inline int
as_ordered(const struct butterflyfish_ordered_incremental_list_i *const object,
           const struct butterflyfish_ordered_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_ordered_list_i *ordered_list;
    seagrass_required_true(!as_ordered_list(object, &ordered_list));
    return INVOKE_ORDERED_LIST(ordered_list)->as_ordered(ordered_list, out);
}

static inline int
as_addable(struct butterflyfish_ordered_incremental_list_i *const object,
           struct butterflyfish_addable_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_list_i *incremental_list;
    seagrass_required_true(!as_incremental_list(object, &incremental_list));
    return INVOKE_INCREMENTAL_LIST(incremental_list)
            ->as_addable(incremental_list, out);
}

static inline int
as_collection(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_collection_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->as_collection(list, out);
}

static inline int
as_stream(const struct butterflyfish_ordered_incremental_list_i *const object,
          const struct butterflyfish_stream_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i -

int butterflyfish_ordered_incremental_list_i_first(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_ordered_incremental_list_i_next(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i -

int butterflyfish_ordered_incremental_list_i_count(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_ordered_incremental_list_i_last(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_ordered_incremental_list_i_prev(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark list_i -

int butterflyfish_ordered_incremental_list_i_get(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const uintmax_t at,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->get(list, at, out);
}

int butterflyfish_ordered_incremental_list_i_at(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct sea_turtle_integer *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->at(list, item, out);
}

#pragma mark addable_i -

int butterflyfish_ordered_incremental_list_i_add(
        struct butterflyfish_ordered_incremental_list_i *const object,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_addable_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, value);
}

int butterflyfish_ordered_incremental_list_i_add_all(
        struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark insertable_i -

int butterflyfish_ordered_incremental_list_i_insert(
        struct butterflyfish_ordered_incremental_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_insertable_i *insertable;
    seagrass_required_true(!as_insertable(object, &insertable));
    return INVOKE_INSERTABLE(insertable)->insert(insertable, item, value);
}

int butterflyfish_ordered_incremental_list_i_insert_all(
        struct butterflyfish_ordered_incremental_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_insertable_i *insertable;
    seagrass_required_true(!as_insertable(object, &insertable));
    return INVOKE_INSERTABLE(insertable)->insert_all(insertable, item, other);
}

#pragma mark ordered_incremental_list_i -

int butterflyfish_ordered_incremental_list_i_as_stream(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_stream_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_ordered_incremental_list_i_as_collection(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_collection_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_ordered_incremental_list_i_as_ordered(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_ordered_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered(object, out);
}

int butterflyfish_ordered_incremental_list_i_as_insertable(
        struct butterflyfish_ordered_incremental_list_i *const object,
        struct butterflyfish_insertable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_insertable(object, out);
}

int butterflyfish_ordered_incremental_list_i_as_addable(
        struct butterflyfish_ordered_incremental_list_i *const object,
        struct butterflyfish_addable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_ordered_incremental_list_i_as_list(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_list(object, out);
}

int butterflyfish_ordered_incremental_list_i_as_incremental_list(
        struct butterflyfish_ordered_incremental_list_i *const object,
        struct butterflyfish_incremental_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_incremental_list(object, out);
}

int butterflyfish_ordered_incremental_list_i_as_ordered_list(
        const struct butterflyfish_ordered_incremental_list_i *const object,
        const struct butterflyfish_ordered_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered_list(object, out);
}
