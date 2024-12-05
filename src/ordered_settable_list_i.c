#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \
    (*(struct butterflyfish_ordered_settable_list_i **) x)
#define INVOKE_SETTABLE_LIST(x) (*(struct butterflyfish_settable_list_i **) x)
#define INVOKE_ORDERED_LIST(x)  (*(struct butterflyfish_ordered_list_i **) x)
#define INVOKE_LIST(x)          (*(struct butterflyfish_list_i **) x)
#define INVOKE_ORDERED(x)       (*(struct butterflyfish_ordered_i **) x)
#define INVOKE_SETTABLE(x)      (*(struct butterflyfish_settable_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i **) x)

static inline int
as_settable_list(struct butterflyfish_ordered_settable_list_i *const object,
                 struct butterflyfish_settable_list_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_settable_list(object, out);
}

static inline int
as_ordered_list(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct butterflyfish_ordered_list_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_ordered_list(object, out);
}

static inline int
as_settable(struct butterflyfish_ordered_settable_list_i *const object,
            struct butterflyfish_settable_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_list_i *settable_list;
    seagrass_required_true(!as_settable_list(object, &settable_list));
    return INVOKE_SETTABLE_LIST(settable_list)
                ->as_settable(settable_list, out);
}

static inline int
as_list(const struct butterflyfish_ordered_settable_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_list_i *settable_list;
    seagrass_required_true(!as_settable_list((void *) object, &settable_list));
    return INVOKE_SETTABLE_LIST(settable_list)->as_list(settable_list, out);
}

static inline int
as_ordered(const struct butterflyfish_ordered_settable_list_i *const object,
           const struct butterflyfish_ordered_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_ordered_list_i *ordered_list;
    seagrass_required_true(!as_ordered_list(object, &ordered_list));
    return INVOKE_ORDERED_LIST(ordered_list)->as_ordered(ordered_list, out);
}

static inline int
as_collection(const struct butterflyfish_ordered_settable_list_i *const object,
              const struct butterflyfish_collection_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->as_collection(list, out);
}

static inline int
as_stream(const struct butterflyfish_ordered_settable_list_i *const object,
          const struct butterflyfish_stream_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(object)->as_stream(collection, out);
}

#pragma mark stream_i -

int butterflyfish_ordered_settable_list_i_first(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_ordered_settable_list_i_next(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i -

int butterflyfish_ordered_settable_list_i_count(
        const struct butterflyfish_ordered_settable_list_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_ordered_settable_list_i_last(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_ordered_settable_list_i_prev(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark list_i -

int butterflyfish_ordered_settable_list_i_get(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const uintmax_t at,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->get(list, at, out);
}

int butterflyfish_ordered_settable_list_i_at(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct sea_turtle_integer *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->at(list, item, out);
}

#pragma mark settable_i -

int butterflyfish_ordered_settable_list_i_set_item(
        struct butterflyfish_ordered_settable_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_i *settable;
    seagrass_required_true(!as_settable(object, &settable));
    return INVOKE_SETTABLE(settable)->set_item(settable, item, value);
}

#pragma mark settable_list_i -

int butterflyfish_ordered_settable_list_i_set(
        struct butterflyfish_ordered_settable_list_i *const object,
        uintmax_t at,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_list_i *settable_list;
    seagrass_required_true(!as_settable_list(object, &settable_list));
    return INVOKE_SETTABLE_LIST(settable_list)->set(settable_list, at, value);
}

#pragma mark ordered_settable_list_i -

int butterflyfish_ordered_settable_list_i_as_stream(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct butterflyfish_stream_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_ordered_settable_list_i_as_collection(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct butterflyfish_collection_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_ordered_settable_list_i_as_settable(
        struct butterflyfish_ordered_settable_list_i *const object,
        struct butterflyfish_settable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_settable(object, out);
}

int butterflyfish_ordered_settable_list_i_as_ordered(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct butterflyfish_ordered_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered(object, out);
}

int butterflyfish_ordered_settable_list_i_as_list(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_list(object, out);
}

int butterflyfish_ordered_settable_list_i_as_settable_list(
        struct butterflyfish_ordered_settable_list_i *const object,
        struct butterflyfish_settable_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_list(object, out);
}

int butterflyfish_ordered_settable_list_i_as_ordered_list(
        const struct butterflyfish_ordered_settable_list_i *const object,
        const struct butterflyfish_ordered_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SETTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered_list(object, out);
}
