#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)               (*(struct butterflyfish_reducible_list_i **) x)
#define INVOKE_LIST(x)          (*(struct butterflyfish_list_i **) x)
#define INVOKE_REMOVABLE(x)     (*(struct butterflyfish_removable_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i **) x)

static inline int
as_removable(struct butterflyfish_reducible_list_i *const object,
             struct butterflyfish_removable_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_removable(object, out);
}

static inline int
as_list(const struct butterflyfish_reducible_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_list(object, out);
}

static inline int
as_collection(const struct butterflyfish_reducible_list_i *const object,
              const struct butterflyfish_collection_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->as_collection(list, out);
}

static inline int
as_stream(const struct butterflyfish_reducible_list_i *const object,
          const struct butterflyfish_stream_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i -

int butterflyfish_reducible_list_i_first(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_reducible_list_i_next(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i -

int butterflyfish_reducible_list_i_count(
        const struct butterflyfish_reducible_list_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_reducible_list_i_last(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_reducible_list_i_prev(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark removable_i -

int butterflyfish_reducible_list_i_remove_item(
        struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer *const item) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    struct butterflyfish_removable_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_item(removable, item);
}

int butterflyfish_reducible_list_i_remove_all_items(
        struct butterflyfish_reducible_list_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_removable_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_all_items(removable, other);
}

#pragma mark list_i -

int butterflyfish_reducible_list_i_get(
        const struct butterflyfish_reducible_list_i *const object,
        const uintmax_t at,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->get(list, at, out);
}

int butterflyfish_reducible_list_i_at(
        const struct butterflyfish_reducible_list_i *const object,
        const struct sea_turtle_integer *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->at(list, item, out);
}

#pragma mark reducible_list_i -

int butterflyfish_reducible_list_i_as_stream(
        const struct butterflyfish_reducible_list_i *const object,
        const struct butterflyfish_stream_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_reducible_list_i_as_collection(
        const struct butterflyfish_reducible_list_i *const object,
        const struct butterflyfish_collection_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_reducible_list_i_as_list(
        const struct butterflyfish_reducible_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_list(object, out);
}

int butterflyfish_reducible_list_i_as_removable(
        struct butterflyfish_reducible_list_i *const object,
        struct butterflyfish_removable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_removable(object, out);
}

int butterflyfish_reducible_list_i_remove(
        struct butterflyfish_reducible_list_i *const object,
        const uintmax_t at) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    return INVOKE(object)->remove(object, at);
}

int butterflyfish_reducible_list_i_remove_all(
        struct butterflyfish_reducible_list_i *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_REDUCIBLE_LIST_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKE(object)->remove_all(object, other);
}

