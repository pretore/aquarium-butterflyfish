#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \
    (*(struct butterflyfish_sorted_mutable_list_i **) x)
#define INVOKE_SORTED_SETTABLE_INCREMENTAL_LIST(x) \
    (*(struct butterflyfish_sorted_settable_incremental_list_i **) x)
#define INVOKE_SORTED_SETTABLE_REDUCIBLE_LIST(x) \
    (*(struct butterflyfish_sorted_settable_reducible_list_i **) x)
#define INVOKE_MUTABLE_LIST(x)  \
    (*(struct butterflyfish_mutable_list_i **) x)
#define INVOKE_SORTED_REDUCIBLE_LIST(x) \
    (*(struct butterflyfish_sorted_reducible_list_i **) x)
#define INVOKE_SORTED_INCREMENTAL_LIST(x) \
    (*(struct butterflyfish_sorted_incremental_list_i **) x)
#define INVOKE_SORTED_SETTABLE_LIST(x) \
    (*(struct butterflyfish_sorted_settable_list_i **) x)
#define INVOKE_SETTABLE_INCREMENTAL_LIST(x) \
    (*(struct butterflyfish_settable_incremental_list_i **) x)
#define INVOKE_SETTABLE_REDUCIBLE_LIST(x) \
    (*(struct butterflyfish_settable_reducible_list_i **) x)
#define INVOKE_REDUCIBLE_LIST(x) \
    (*(struct butterflyfish_reducible_list_i **) x)
#define INVOKE_INCREMENTAL_LIST(x) \
    (*(struct butterflyfish_incremental_list_i **) x)
#define INVOKE_SETTABLE_LIST(x) (*(struct butterflyfish_settable_list_i **) x)
#define INVOKE_SORTED_LIST(x)   (*(struct butterflyfish_sorted_list_i **) x)
#define INVOKE_REMOVABLE(x)     (*(struct butterflyfish_removable_i **) x)
#define INVOKE_LIST(x)          (*(struct butterflyfish_list_i **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_i **) x)
#define INVOKE_SETTABLE(x)      (*(struct butterflyfish_settable_i **) x)
#define INVOKE_SORTED(x)        (*(struct butterflyfish_sorted_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i **) x)

static inline int
as_sorted_settable_incremental_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_settable_incremental_list_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_sorted_settable_incremental_list(object, out);
}

static inline int
as_sorted_settable_reducible_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_settable_reducible_list_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_sorted_settable_reducible_list(object, out);
}

static inline int
as_sorted_settable_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_settable_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_incremental_list_i
            *sorted_settable_incremental_list;
    seagrass_required_true(!as_sorted_settable_incremental_list(
            object, &sorted_settable_incremental_list));
    return INVOKE_SORTED_SETTABLE_INCREMENTAL_LIST(sorted_settable_incremental_list)
        ->as_sorted_settable_list(sorted_settable_incremental_list, out);
}

static inline int
as_sorted_incremental_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_incremental_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_incremental_list_i
            *sorted_settable_incremental_list;
    seagrass_required_true(!as_sorted_settable_incremental_list(
            object, &sorted_settable_incremental_list));
    return INVOKE_SORTED_SETTABLE_INCREMENTAL_LIST(sorted_settable_incremental_list)
        ->as_sorted_incremental_list(sorted_settable_incremental_list, out);
}

static inline int
as_sorted_reducible_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_reducible_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_reducible_list_i
            *sorted_settable_reducible_list;
    seagrass_required_true(!as_sorted_settable_reducible_list(
            object, &sorted_settable_reducible_list));
    return INVOKE_SORTED_SETTABLE_REDUCIBLE_LIST(sorted_settable_reducible_list)
            ->as_sorted_reducible_list(sorted_settable_reducible_list, out);
}

static inline int
as_mutable_list(struct butterflyfish_sorted_mutable_list_i *const object,
                struct butterflyfish_mutable_list_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_mutable_list(object, out);
}

static inline int
as_settable_incremental_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_settable_incremental_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_mutable_list_i *mutable_list;
    seagrass_required_true(!as_mutable_list(object, &mutable_list));
    return INVOKE_MUTABLE_LIST(mutable_list)
            ->as_settable_incremental_list(mutable_list, out);
}

static inline int
as_settable_reducible_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_settable_reducible_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_mutable_list_i *mutable_list;
    seagrass_required_true(!as_mutable_list(object, &mutable_list));
    return INVOKE_MUTABLE_LIST(mutable_list)
            ->as_settable_reducible_list(mutable_list, out);
}

static inline int
as_sorted_list(const struct butterflyfish_sorted_mutable_list_i *const object,
               const struct butterflyfish_sorted_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_list_i *sorted_settable_list;
    seagrass_required_true(!as_sorted_settable_list(
            (void *) object, &sorted_settable_list));
    return INVOKE_SORTED_SETTABLE_LIST(sorted_settable_list)
        ->as_sorted_list(sorted_settable_list, out);
}

static inline int
as_settable_list(struct butterflyfish_sorted_mutable_list_i *const object,
                 struct butterflyfish_settable_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_list_i *sorted_settable_list;
    seagrass_required_true(!as_sorted_settable_list(
            object, &sorted_settable_list));
    return INVOKE_SORTED_SETTABLE_LIST(sorted_settable_list)
            ->as_settable_list(sorted_settable_list, out);
}

static inline int
as_incremental_list(struct butterflyfish_sorted_mutable_list_i *const object,
                    struct butterflyfish_incremental_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_incremental_list_i *sorted_incremental_list;
    seagrass_required_true(!as_sorted_incremental_list(
            object, &sorted_incremental_list));
    return INVOKE_SORTED_INCREMENTAL_LIST(sorted_incremental_list)
            ->as_incremental_list(sorted_incremental_list, out);
}

static inline int
as_reducible_list(struct butterflyfish_sorted_mutable_list_i *const object,
                  struct butterflyfish_reducible_list_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_reducible_list_i *sorted_reducible_list;
    seagrass_required_true(!as_sorted_reducible_list(
            object, &sorted_reducible_list));
    return INVOKE_SORTED_REDUCIBLE_LIST(sorted_reducible_list)
            ->as_reducible_list(sorted_reducible_list, out);
}

static inline int
as_sorted(const struct butterflyfish_sorted_mutable_list_i *const object,
          const struct butterflyfish_sorted_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_sorted_list_i *sorted_list;
    seagrass_required_true(!as_sorted_list(object, &sorted_list));
    return INVOKE_SORTED_LIST(sorted_list)->as_sorted(sorted_list, out);
}

static inline int
as_settable(struct butterflyfish_sorted_mutable_list_i *const object,
            struct butterflyfish_settable_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_list_i *settable_list;
    seagrass_required_true(!as_settable_list(object, &settable_list));
    return INVOKE_SETTABLE_LIST(settable_list)->as_settable(settable_list, out);
}

static inline int
as_addable(struct butterflyfish_sorted_mutable_list_i *const object,
           struct butterflyfish_addable_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_list_i *incremental_list;
    seagrass_required_true(!as_incremental_list(object, &incremental_list));
    return INVOKE_INCREMENTAL_LIST(incremental_list)
        ->as_addable(incremental_list, out);
}

static inline int
as_list(const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_sorted_list_i *sorted_list;
    seagrass_required_true(!as_sorted_list(object, &sorted_list));
    return INVOKE_SORTED_LIST(sorted_list)->as_list(sorted_list, out);
}

static inline int
as_removable(struct butterflyfish_sorted_mutable_list_i *const object,
             struct butterflyfish_removable_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_reducible_list_i *reducible_list;
    seagrass_required_true(!as_reducible_list(object, &reducible_list));
    return INVOKE_REDUCIBLE_LIST(reducible_list)
        ->as_removable(reducible_list, out);
}

static inline int
as_collection(const struct butterflyfish_sorted_mutable_list_i *const object,
              const struct butterflyfish_collection_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_sorted_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->as_collection(sorted, out);
}

static inline int
as_stream(const struct butterflyfish_sorted_mutable_list_i *const object,
          const struct butterflyfish_stream_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i -

int butterflyfish_sorted_mutable_list_i_first(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_sorted_mutable_list_i_next(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i -

int butterflyfish_sorted_mutable_list_i_count(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_sorted_mutable_list_i_last(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_sorted_mutable_list_i_prev(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark sorted_i -

int butterflyfish_sorted_mutable_list_i_ceiling(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->ceiling(sorted, value, out);
}

int butterflyfish_sorted_mutable_list_i_floor(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->floor(sorted, value, out);
}

int butterflyfish_sorted_mutable_list_i_higher(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->higher(sorted, value, out);
}

int butterflyfish_sorted_mutable_list_i_lower(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->lower(sorted, value, out);
}

#pragma mark settable_i -

int butterflyfish_sorted_mutable_list_i_set_item(
        struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_i *settable;
    seagrass_required_true(!as_settable(object, &settable));
    return INVOKE_SETTABLE(settable)->set_item(settable, item, value);
}

#pragma mark addable_i -

int butterflyfish_sorted_mutable_list_i_add(
        struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_addable_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, value);
}

int butterflyfish_sorted_mutable_list_i_add_all(
        struct butterflyfish_sorted_mutable_list_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark list_i -

int butterflyfish_sorted_mutable_list_i_get(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const uintmax_t at,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->get(list, at, out);
}

int butterflyfish_sorted_mutable_list_i_at(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const item,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_list_i *list;
    seagrass_required_true(!as_list(object, &list));
    return INVOKE_LIST(list)->at(list, item, out);
}

#pragma mark removable_i -

int butterflyfish_sorted_mutable_list_i_remove_item(
        struct butterflyfish_sorted_mutable_list_i *const object,
        const struct sea_turtle_integer *const item) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_ITEM_IS_NULL;
    }
    struct butterflyfish_removable_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_item(removable, item);
}

int butterflyfish_sorted_mutable_list_i_remove_all_items(
        struct butterflyfish_sorted_mutable_list_i *object,
        const struct butterflyfish_stream_i *other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_removable_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_all_items(removable, other);
}

#pragma mark settable_list_i -

int butterflyfish_sorted_mutable_list_i_set(
        struct butterflyfish_sorted_mutable_list_i *const object,
        const uintmax_t at,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_list_i *settable_list;
    seagrass_required_true(!as_settable_list(object, &settable_list));
    return INVOKE_SETTABLE_LIST(settable_list)->set(settable_list, at, value);
}

#pragma mark reducible_list_i -

int butterflyfish_sorted_mutable_list_i_remove(
        struct butterflyfish_sorted_mutable_list_i *const object,
        const uintmax_t at) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    struct butterflyfish_reducible_list_i *reducible_list;
    seagrass_required_true(!as_reducible_list(object, &reducible_list));
    return INVOKE_REDUCIBLE_LIST(reducible_list)->remove(reducible_list, at);
}

int butterflyfish_sorted_mutable_list_i_remove_all(
        struct butterflyfish_sorted_mutable_list_i *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_reducible_list_i *reducible_list;
    seagrass_required_true(!as_reducible_list(object, &reducible_list));
    return INVOKE_REDUCIBLE_LIST(reducible_list)
        ->remove_all(reducible_list, other);
}

#pragma mark sorted_mutable_list_i -

int butterflyfish_sorted_mutable_list_i_as_stream(
        const struct butterflyfish_sorted_mutable_list_i *object,
        const struct butterflyfish_stream_i **out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_collection(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct butterflyfish_collection_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_sorted(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct butterflyfish_sorted_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_settable(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_settable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_settable(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_addable(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_addable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_list(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_removable(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_removable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_removable(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_sorted_list(
        const struct butterflyfish_sorted_mutable_list_i *const object,
        const struct butterflyfish_sorted_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_settable_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_settable_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_incremental_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_incremental_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_incremental_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_reducible_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_reducible_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_reducible_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_settable_incremental_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_settable_incremental_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_incremental_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_settable_reducible_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_settable_reducible_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_reducible_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_sorted_settable_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_settable_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_settable_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_sorted_incremental_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_incremental_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_incremental_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_sorted_reducible_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_reducible_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_reducible_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_mutable_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_mutable_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_mutable_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_sorted_settable_incremental_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_settable_incremental_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_settable_incremental_list(object, out);
}

int butterflyfish_sorted_mutable_list_i_as_sorted_settable_reducible_list(
        struct butterflyfish_sorted_mutable_list_i *const object,
        struct butterflyfish_sorted_settable_reducible_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_LIST_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_settable_reducible_list(object, out);
}
