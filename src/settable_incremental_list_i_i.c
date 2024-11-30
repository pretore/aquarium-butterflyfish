#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \
    (*(struct butterflyfish_settable_incremental_list_i_i **) x)
#define INVOKE_INCREMENTAL_LIST(x) \
    (*(struct butterflyfish_incremental_list_i_i **) x)
#define INVOKE_SETTABLE_LIST(x) (*(struct butterflyfish_settable_list_i_i **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_i_i **) x)
#define INVOKE_LIST(x)          (*(struct butterflyfish_list_i_i **) x)
#define INVOKE_SETTABLE(x)      (*(struct butterflyfish_settable_i_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i_i **) x)

static inline int
as_incremental_list(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        struct butterflyfish_incremental_list_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_incremental_list(object, out);
}

static inline int
as_settable_list(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        struct butterflyfish_settable_list_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_settable_list(object, out);
}

static inline int
as_settable(struct butterflyfish_settable_incremental_list_i_i *const object,
            struct butterflyfish_settable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_list_i_i *settable_list;
    seagrass_required_true(!as_settable_list(object, &settable_list));
    return INVOKE_SETTABLE_LIST(settable_list)->as_settable(settable_list, out);
}

static inline int
as_list(const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_list_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_list_i_i *settable_list;
    seagrass_required_true(!as_settable_list((void *) object, &settable_list));
    return INVOKE_SETTABLE_LIST(settable_list)->as_list(settable_list, out);
}

static inline int
as_addable(struct butterflyfish_settable_incremental_list_i_i *const object,
           struct butterflyfish_addable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_list_i_i *incremental_list;
    seagrass_required_true(!as_incremental_list(object, &incremental_list));
    return INVOKE_INCREMENTAL_LIST(incremental_list)
        ->as_addable(incremental_list, out);
}

static inline int
as_collection(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_collection_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_i_i *settable;
    seagrass_required_true(!as_settable((void *) object, &settable));
    return INVOKE_SETTABLE(settable)->as_collection(settable, out);
}

static inline int
as_stream(const struct butterflyfish_settable_incremental_list_i_i *const object,
          const struct butterflyfish_stream_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i_i -

int butterflyfish_settable_incremental_list_i_i_first(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_settable_incremental_list_i_i_next(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i_i -

int butterflyfish_settable_incremental_list_i_i_count(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_settable_incremental_list_i_i_last(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_settable_incremental_list_i_i_prev(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark list_i_i -

int butterflyfish_settable_incremental_list_i_i_get(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const uintmax_t at,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->get(list, at, out);
}

int butterflyfish_settable_incremental_list_i_i_at(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->at(list, item, out);
}

#pragma mark settable_i_i -

int butterflyfish_settable_incremental_list_i_i_set_item(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_i_i *settable;
    seagrass_required_true(!as_settable(object, &settable));
    return INVOKE_SETTABLE(settable)->set_item(settable, item, value);
}

#pragma mark settable_list_i_i -

int butterflyfish_settable_incremental_list_i_i_set(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        uintmax_t at,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_list_i_i *settable_list;
    seagrass_required_true(!as_settable_list(object, &settable_list));
    return INVOKE_SETTABLE_LIST(settable_list)->set(settable_list, at, value);
}

#pragma mark addable_i_i -

int butterflyfish_settable_incremental_list_i_i_add(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_addable_i_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, value);
}

int butterflyfish_settable_incremental_list_i_i_add_all(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_i_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark settable_incremental_i_i -

int butterflyfish_settable_incremental_list_i_i_as_stream(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_stream_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_settable_incremental_list_i_i_as_collection(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_collection_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_settable_incremental_list_i_i_as_settable(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        struct butterflyfish_settable_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable(object, out);
}

int butterflyfish_settable_incremental_list_i_i_as_list(
        const struct butterflyfish_settable_incremental_list_i_i *const object,
        const struct butterflyfish_list_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    return as_list(object, out);
}

int butterflyfish_settable_incremental_list_i_i_as_addable(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        struct butterflyfish_addable_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_settable_incremental_list_i_i_as_settable_list(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        struct butterflyfish_settable_list_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_list(object, out);
}

int butterflyfish_settable_incremental_list_i_i_as_incremental_list(
        struct butterflyfish_settable_incremental_list_i_i *const object,
        struct butterflyfish_incremental_list_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_LIST_I_I_ERROR_OUT_IS_NULL;
    }
    return as_incremental_list(object, out);
}

