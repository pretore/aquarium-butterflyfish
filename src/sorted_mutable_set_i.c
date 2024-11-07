#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \
    (*(struct butterflyfish_sorted_mutable_set_i **) x)
#define INVOKE_SORTED_SETTABLE_INCREMENTAL_SET(x) \
    (*(struct butterflyfish_sorted_settable_incremental_set_i **) x)
#define INVOKE_SORTED_SETTABLE_REDUCIBLE_SET(x) \
    (*(struct butterflyfish_sorted_settable_reducible_set_i **) x)
#define INVOKE_SORTED_SETTABLE_SET(x) \
    (*(struct butterflyfish_sorted_settable_set_i **) x)
#define INVOKE_SORTED_INCREMENTAL_SET(x) \
    (*(struct butterflyfish_sorted_incremental_set_i **) x)
#define INVOKE_SORTED_REDUCIBLE_SET(x) \
    (*(struct butterflyfish_sorted_reducible_set_i **) x)
#define INVOKE_SORTED(x) \
    (*(struct butterflyfish_sorted_i **) x)
#define INVOKE_SORTED_SET(x) \
    (*(struct butterflyfish_sorted_set_i **) x)
#define INVOKE_MUTABLE_SET(x) \
    (*(struct butterflyfish_mutable_set_i **) x)
#define INVOKE_SETTABLE_SET(x) \
    (*(struct butterflyfish_settable_set_i **) x)
#define INVOKE_INCREMENTAL_SET(x) \
    (*(struct butterflyfish_incremental_set_i **) x)
#define INVOKE_REDUCIBLE_SET(x) \
    (*(struct butterflyfish_reducible_set_i **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_i **) x)
#define INVOKE_SETTABLE(x)      (*(struct butterflyfish_settable_i **) x)
#define INVOKE_REMOVABLE(x)     (*(struct butterflyfish_removable_i **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i **) x)

static inline int
as_mutable_set(struct butterflyfish_sorted_mutable_set_i *const object,
               struct butterflyfish_mutable_set_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_mutable_set(object, out);
}

static inline int
as_sorted_settable_incremental_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_settable_incremental_set_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_sorted_settable_incremental_set(object, out);
}

static inline int
as_sorted_settable_reducible_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_settable_reducible_set_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_sorted_settable_reducible_set(object, out);
}

static inline int
as_sorted_settable_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_settable_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_incremental_set_i
            *sorted_settable_incremental_set;
    seagrass_required_true(!as_sorted_settable_incremental_set(
            object, &sorted_settable_incremental_set));
    return INVOKE_SORTED_SETTABLE_INCREMENTAL_SET(sorted_settable_incremental_set)
            ->as_sorted_settable_set(sorted_settable_incremental_set, out);
}

static inline int
as_sorted_incremental_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_incremental_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_incremental_set_i
            *sorted_settable_incremental_set;
    seagrass_required_true(!as_sorted_settable_incremental_set(
            object, &sorted_settable_incremental_set));
    return INVOKE_SORTED_SETTABLE_INCREMENTAL_SET(sorted_settable_incremental_set)
        ->as_sorted_incremental_set(sorted_settable_incremental_set, out);
}

static inline int
as_sorted_reducible_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_reducible_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_reducible_set_i
            *sorted_settable_reducible_set;
    seagrass_required_true(!as_sorted_settable_reducible_set(
            object, &sorted_settable_reducible_set));
    return INVOKE_SORTED_SETTABLE_REDUCIBLE_SET(sorted_settable_reducible_set)
        ->as_sorted_reducible_set(sorted_settable_reducible_set, out);
}

static inline int
as_sorted_set(const struct butterflyfish_sorted_mutable_set_i *const object,
              const struct butterflyfish_sorted_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_set_i *sorted_settable_set;
    seagrass_required_true(!as_sorted_settable_set(
            (void *) object, &sorted_settable_set));
    return INVOKE_SORTED_SETTABLE_SET(sorted_settable_set)
            ->as_sorted_set(sorted_settable_set, out);
}

static inline int
as_sorted(const struct butterflyfish_sorted_mutable_set_i *const object,
          const struct butterflyfish_sorted_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_sorted_set_i *sorted_set;
    seagrass_required_true(!as_sorted_set(object, &sorted_set));
    return INVOKE_SORTED_SET(sorted_set)->as_sorted(sorted_set, out);
}

static inline int
as_settable_incremental_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_settable_incremental_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_mutable_set_i *mutable_set;
    seagrass_required_true(!as_mutable_set(object, &mutable_set));
    return INVOKE_MUTABLE_SET(mutable_set)
            ->as_settable_incremental_set(mutable_set, out);
}

static inline int
as_settable_reducible_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_settable_reducible_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_mutable_set_i *mutable_set;
    seagrass_required_true(!as_mutable_set(object, &mutable_set));
    return INVOKE_MUTABLE_SET(mutable_set)
            ->as_settable_reducible_set(mutable_set, out);
}

static inline int
as_settable_set(struct butterflyfish_sorted_mutable_set_i *const object,
                struct butterflyfish_settable_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_set_i *sorted_settable_set;
    seagrass_required_true(!as_sorted_settable_set(
            object, &sorted_settable_set));
    return INVOKE_SORTED_SETTABLE_SET(sorted_settable_set)
            ->as_settable_set(sorted_settable_set, out);
}

static inline int
as_incremental_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_incremental_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_incremental_set_i *sorted_incremental_set;
    seagrass_required_true(!as_sorted_incremental_set(
            object, &sorted_incremental_set));
    return INVOKE_SORTED_INCREMENTAL_SET(sorted_incremental_set)
            ->as_incremental_set(sorted_incremental_set, out);
}

static inline int
as_reducible_set(struct butterflyfish_sorted_mutable_set_i *const object,
                 struct butterflyfish_reducible_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_reducible_set_i *sorted_reducible_set;
    seagrass_required_true(!as_sorted_reducible_set(
            object, &sorted_reducible_set));
    return INVOKE_SORTED_REDUCIBLE_SET(sorted_reducible_set)
            ->as_reducible_set(sorted_reducible_set, out);
}

static inline int
as_set(const struct butterflyfish_sorted_mutable_set_i *const object,
       const struct butterflyfish_set_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_set_i *settable_set;
    seagrass_required_true(!as_settable_set((void *) object, &settable_set));
    return INVOKE_SETTABLE_SET(settable_set)->as_set(settable_set, out);
}

static inline int
as_removable(struct butterflyfish_sorted_mutable_set_i *const object,
             struct butterflyfish_removable_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_reducible_set_i *reducible_set_i;
    seagrass_required_true(!as_reducible_set(object, &reducible_set_i));
    return INVOKE_REDUCIBLE_SET(reducible_set_i)
            ->as_removable(reducible_set_i, out);
}

static inline int
as_addable(struct butterflyfish_sorted_mutable_set_i *const object,
           struct butterflyfish_addable_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_set_i *incremental_set;
    seagrass_required_true(!as_incremental_set(
            object, &incremental_set));
    return INVOKE_INCREMENTAL_SET(incremental_set)
            ->as_addable(incremental_set, out);
}

static inline int
as_settable(struct butterflyfish_sorted_mutable_set_i *const object,
            struct butterflyfish_settable_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_set_i *settable_set;
    seagrass_required_true(!as_settable_set(object, &settable_set));
    return INVOKE_SETTABLE_SET(settable_set)->as_settable(settable_set, out);
}

static inline int
as_collection(const struct butterflyfish_sorted_mutable_set_i *const object,
              const struct butterflyfish_collection_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(const struct butterflyfish_sorted_mutable_set_i *const object,
          const struct butterflyfish_stream_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i -

int butterflyfish_sorted_mutable_set_i_first(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_sorted_mutable_set_i_next(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i -

int butterflyfish_sorted_mutable_set_i_count(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_sorted_mutable_set_i_last(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_sorted_mutable_set_i_prev(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark settable_i -

int butterflyfish_sorted_mutable_set_i_set_item(
        struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_i *settable;
    seagrass_required_true(!as_settable(object, &settable));
    return INVOKE_SETTABLE(settable)->set_item(settable, item, value);
}

#pragma mark sorted_i -

int butterflyfish_sorted_mutable_set_i_ceiling(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->ceiling(sorted, value, out);
}

int butterflyfish_sorted_mutable_set_i_floor(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->floor(sorted, value, out);
}

int butterflyfish_sorted_mutable_set_i_higher(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->higher(sorted, value, out);
}

int butterflyfish_sorted_mutable_set_i_lower(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->lower(sorted, value, out);
}

#pragma mark set_i -

int butterflyfish_sorted_mutable_set_i_contains(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, value, out);
}

int butterflyfish_sorted_mutable_set_i_contains_all(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_stream_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_sorted_mutable_set_i_get(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, value, out);
}

#pragma mark settable_set_i -

int butterflyfish_sorted_mutable_set_i_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_set_i *settable_set;
    seagrass_required_true(!as_settable_set(object, &settable_set));
    return INVOKE_SETTABLE_SET(settable_set)->set(settable_set, item, value);
}

#pragma mark addable_i -

int butterflyfish_sorted_mutable_set_i_add(
        struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_addable_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, value);
}

int butterflyfish_sorted_mutable_set_i_add_all(
        struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark removable_i -

int butterflyfish_sorted_mutable_set_i_remove_item(
        struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const item) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_ITEM_IS_NULL;
    }
    struct butterflyfish_removable_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_item(removable, item);
}

int butterflyfish_sorted_mutable_set_i_remove_all_items(
        struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_removable_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_all_items(removable, other);
}

#pragma mark reducible_set_i -

int butterflyfish_sorted_mutable_set_i_remove(
        struct butterflyfish_sorted_mutable_set_i *const object,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_reducible_set_i *reducible_set;
    seagrass_required_true(!as_reducible_set(
            object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)->remove(reducible_set, value);
}

int butterflyfish_sorted_mutable_set_i_remove_all(
        struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_reducible_set_i *reducible_set;
    seagrass_required_true(!as_reducible_set(
            object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)
            ->remove_all(reducible_set, other);
}

int butterflyfish_sorted_mutable_set_i_retain_all(
        struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_reducible_set_i *reducible_set;
    seagrass_required_true(!as_reducible_set(
            object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)
            ->retain_all(reducible_set, other);
}

#pragma mark sorted_mutable_set_i -

int butterflyfish_sorted_mutable_set_i_as_stream(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_stream_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_addable(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_addable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_collection(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_collection_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_settable(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_settable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_settable(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_sorted(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_sorted_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_set(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_removable(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_removable_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_removable(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_settable_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_settable_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_incremental_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_incremental_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_incremental_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_reducible_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_reducible_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_reducible_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_settable_incremental_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_settable_incremental_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_incremental_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_settable_reducible_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_settable_reducible_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_reducible_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_mutable_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_mutable_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_mutable_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_sorted_set(
        const struct butterflyfish_sorted_mutable_set_i *const object,
        const struct butterflyfish_sorted_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_sorted_settable_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_settable_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_settable_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_sorted_incremental_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_incremental_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_incremental_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_sorted_reducible_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_reducible_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_reducible_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_sorted_settable_incremental_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_settable_incremental_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_settable_incremental_set(object, out);
}

int butterflyfish_sorted_mutable_set_i_as_sorted_settable_reducible_set(
        struct butterflyfish_sorted_mutable_set_i *const object,
        struct butterflyfish_sorted_settable_reducible_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MUTABLE_SET_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_settable_reducible_set(object, out);
}
