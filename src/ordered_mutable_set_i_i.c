#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \
    (*(struct butterflyfish_ordered_mutable_set_i_i **) x)
#define INVOKE_ORDERED_SETTABLE_INCREMENTAL_SET(x) \
    (*(struct butterflyfish_ordered_settable_incremental_set_i_i **) x)
#define INVOKE_ORDERED_SETTABLE_REDUCIBLE_SET(x) \
    (*(struct butterflyfish_ordered_settable_reducible_set_i_i **) x)
#define INVOKE_ORDERED_SETTABLE_SET(x) \
    (*(struct butterflyfish_ordered_settable_set_i_i **) x)
#define INVOKE_ORDERED_INCREMENTAL_SET(x) \
    (*(struct butterflyfish_ordered_incremental_set_i_i **) x)
#define INVOKE_ORDERED_REDUCIBLE_SET(x) \
    (*(struct butterflyfish_ordered_reducible_set_i_i **) x)
#define INVOKE_MUTABLE_SET(x) \
    (*(struct butterflyfish_mutable_set_i_i **) x)
#define INVOKE_ORDERED_SET(x) \
    (*(struct butterflyfish_ordered_set_i_i **) x)
#define INVOKE_SETTABLE_INCREMENTAL_SET(x) \
    (*(struct butterflyfish_settable_incremental_set_i_i **) x)
#define INVOKE_SETTABLE_REDUCIBLE_SET(x) \
    (*(struct butterflyfish_settable_reducible_set_i_i **) x)
#define INVOKE_SETTABLE_SET(x) \
    (*(struct butterflyfish_settable_set_i_i **) x)
#define INVOKE_INCREMENTAL_SET(x) \
    (*(struct butterflyfish_incremental_set_i_i **) x)
#define INVOKE_REDUCIBLE_SET(x) \
    (*(struct butterflyfish_reducible_set_i_i **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_i_i **) x)
#define INVOKE_INSERTABLE(x)    (*(struct butterflyfish_insertable_i_i **) x)
#define INVOKE_ORDERED(x)       (*(struct butterflyfish_ordered_i_i **) x)
#define INVOKE_SETTABLE(x)      (*(struct butterflyfish_settable_i_i **) x)
#define INVOKE_REMOVABLE(x)     (*(struct butterflyfish_removable_i_i **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_i_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i_i **) x)

static inline int
as_ordered_settable_incremental_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_settable_incremental_set_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_ordered_settable_incremental_set(object, out);
}

static inline int
as_ordered_settable_reducible_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_settable_reducible_set_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_ordered_settable_reducible_set(object, out);
}

static inline int
as_ordered_settable_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_settable_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_settable_incremental_set_i_i
            *ordered_settable_incremental_set;
    seagrass_required_true(!as_ordered_settable_incremental_set(
            object, &ordered_settable_incremental_set));
    return INVOKE_ORDERED_SETTABLE_INCREMENTAL_SET(ordered_settable_incremental_set)
        ->as_ordered_settable_set(ordered_settable_incremental_set, out);
}

static inline int
as_ordered_incremental_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_incremental_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_settable_incremental_set_i_i
            *ordered_settable_incremental_set;
    seagrass_required_true(!as_ordered_settable_incremental_set(
            object, &ordered_settable_incremental_set));
    return INVOKE_ORDERED_SETTABLE_INCREMENTAL_SET(ordered_settable_incremental_set)
        ->as_ordered_incremental_set(ordered_settable_incremental_set, out);
}

static inline int
as_ordered_reducible_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_reducible_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_settable_reducible_set_i_i
            *ordered_settable_reducible_set;
    seagrass_required_true(!as_ordered_settable_reducible_set(
            object, &ordered_settable_reducible_set));
    return INVOKE_ORDERED_SETTABLE_REDUCIBLE_SET(ordered_settable_reducible_set)
        ->as_ordered_reducible_set(ordered_settable_reducible_set, out);
}

static inline int
as_mutable_set(struct butterflyfish_ordered_mutable_set_i_i *const object,
               struct butterflyfish_mutable_set_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_mutable_set(object, out);
}

static inline int
as_ordered_set(const struct butterflyfish_ordered_mutable_set_i_i *const object,
               const struct butterflyfish_ordered_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_settable_set_i_i *ordered_settable_set;
    seagrass_required_true(!as_ordered_settable_set(
            (void *) object, &ordered_settable_set));
    return INVOKE_ORDERED_SETTABLE_SET(ordered_settable_set)
            ->as_ordered_set(ordered_settable_set, out);
}

static inline int
as_settable_incremental_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_settable_incremental_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_mutable_set_i_i *mutable_set;
    seagrass_required_true(!as_mutable_set(object, &mutable_set));
    return INVOKE_MUTABLE_SET(mutable_set)
            ->as_settable_incremental_set(mutable_set, out);
}

static inline int
as_settable_reducible_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_settable_reducible_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_mutable_set_i_i *mutable_set;
    seagrass_required_true(!as_mutable_set(object, &mutable_set));
    return INVOKE_MUTABLE_SET(mutable_set)
            ->as_settable_reducible_set(mutable_set, out);
}

static inline int
as_settable_set(struct butterflyfish_ordered_mutable_set_i_i *const object,
                struct butterflyfish_settable_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_settable_set_i_i *ordered_settable_set;
    seagrass_required_true(!as_ordered_settable_set(
            object, &ordered_settable_set));
    return INVOKE_ORDERED_SETTABLE_SET(ordered_settable_set)
            ->as_settable_set(ordered_settable_set, out);
}

static inline int
as_incremental_set(struct butterflyfish_ordered_mutable_set_i_i *const object,
                   struct butterflyfish_incremental_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_incremental_set_i_i *ordered_incremental_set;
    seagrass_required_true(!as_ordered_incremental_set(
            object, &ordered_incremental_set));
    return INVOKE_ORDERED_INCREMENTAL_SET(ordered_incremental_set)
            ->as_incremental_set(ordered_incremental_set, out);
}

static inline int
as_reducible_set(struct butterflyfish_ordered_mutable_set_i_i *const object,
                 struct butterflyfish_reducible_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_reducible_set_i_i *ordered_reducible_set;
    seagrass_required_true(!as_ordered_reducible_set(
            object, &ordered_reducible_set));
    return INVOKE_ORDERED_REDUCIBLE_SET(ordered_reducible_set)
            ->as_reducible_set(ordered_reducible_set, out);
}

static inline int
as_set(const struct butterflyfish_ordered_mutable_set_i_i *const object,
       const struct butterflyfish_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_set_i_i *settable_set;
    seagrass_required_true(!as_settable_set((void *) object, &settable_set));
    return INVOKE_SETTABLE_SET(settable_set)->as_set(settable_set, out);
}

static inline int
as_removable(struct butterflyfish_ordered_mutable_set_i_i *const object,
             struct butterflyfish_removable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_reducible_set_i_i *reducible_set;
    seagrass_required_true(!as_reducible_set(object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)
            ->as_removable(reducible_set, out);
}

static inline int
as_addable(struct butterflyfish_ordered_mutable_set_i_i *const object,
           struct butterflyfish_addable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_set_i_i *incremental_set;
    seagrass_required_true(!as_incremental_set(object, &incremental_set));
    return INVOKE_INCREMENTAL_SET(incremental_set)
            ->as_addable(incremental_set, out);
}

static inline int
as_settable(struct butterflyfish_ordered_mutable_set_i_i *const object,
            struct butterflyfish_settable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_set_i_i *settable_set;
    seagrass_required_true(!as_settable_set(object, &settable_set));
    return INVOKE_SETTABLE_SET(settable_set)->as_settable(settable_set, out);
}

static inline int
as_ordered(const struct butterflyfish_ordered_mutable_set_i_i *const object,
           const struct butterflyfish_ordered_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_ordered_set_i_i *ordered_set;
    seagrass_required_true(!as_ordered_set(object, &ordered_set));
    return INVOKE_ORDERED_SET(ordered_set)->as_ordered(ordered_set, out);
}

static inline int
as_insertable(struct butterflyfish_ordered_mutable_set_i_i *const object,
              struct butterflyfish_insertable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_incremental_set_i_i *ordered_incremental_set;
    seagrass_required_true(!as_ordered_incremental_set(
            object, &ordered_incremental_set));
    return INVOKE_ORDERED_INCREMENTAL_SET(ordered_incremental_set)
            ->as_insertable(ordered_incremental_set, out);
}

static inline int
as_collection(const struct butterflyfish_ordered_mutable_set_i_i *const object,
              const struct butterflyfish_collection_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(const struct butterflyfish_ordered_mutable_set_i_i *const object,
          const struct butterflyfish_stream_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i_i -

int butterflyfish_ordered_mutable_set_i_i_first(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_ordered_mutable_set_i_i_next(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i_i -

int butterflyfish_ordered_mutable_set_i_i_count(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_ordered_mutable_set_i_i_last(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_ordered_mutable_set_i_i_prev(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark settable_i_i -

int butterflyfish_ordered_mutable_set_i_i_set_item(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_i_i *settable;
    seagrass_required_true(!as_settable(object, &settable));
    return INVOKE_SETTABLE(settable)->set_item(settable, item, value);
}

#pragma mark set_i_i -

int butterflyfish_ordered_mutable_set_i_i_contains(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, value, out);
}

int butterflyfish_ordered_mutable_set_i_i_contains_all(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_ordered_mutable_set_i_i_get(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, value, out);
}

#pragma mark settable_set_i_i -

int butterflyfish_ordered_mutable_set_i_i_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_set_i_i *settable_set;
    seagrass_required_true(!as_settable_set(object, &settable_set));
    return INVOKE_SETTABLE_SET(settable_set)->set(settable_set, item, value);
}

#pragma mark addable_i_i -

int butterflyfish_ordered_mutable_set_i_i_add(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_addable_i_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, value);
}

int butterflyfish_ordered_mutable_set_i_i_add_all(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_i_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark removable_i_i -

int butterflyfish_ordered_mutable_set_i_i_remove_item(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    struct butterflyfish_removable_i_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_item(removable, item);
}

int butterflyfish_ordered_mutable_set_i_i_remove_all_items(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_removable_i_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_all_items(removable, other);
}

#pragma mark insertable_i_i -

int butterflyfish_ordered_mutable_set_i_i_insert(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_insertable_i_i *insertable;
    seagrass_required_true(!as_insertable(object, &insertable));
    return INVOKE_INSERTABLE(insertable)->insert(insertable, item, value);
}

int butterflyfish_ordered_mutable_set_i_i_insert_all(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_insertable_i_i *insertable;
    seagrass_required_true(!as_insertable(object, &insertable));
    return INVOKE_INSERTABLE(insertable)->insert_all(insertable, item, other);
}

#pragma mark reducible_set_i_i -

int butterflyfish_ordered_mutable_set_i_i_remove(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_reducible_set_i_i *reducible_set;
    seagrass_required_true(!as_reducible_set(object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)->remove(reducible_set, value);
}

int butterflyfish_ordered_mutable_set_i_i_remove_all(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_reducible_set_i_i *reducible_set;
    seagrass_required_true(!as_reducible_set(object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)
            ->remove_all(reducible_set, other);
}

int butterflyfish_ordered_mutable_set_i_i_retain_all(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_reducible_set_i_i *reducible_set;
    seagrass_required_true(!as_reducible_set(object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)
            ->retain_all(reducible_set, other);
}

#pragma mark ordered_mutable_set_i_i -

int butterflyfish_ordered_mutable_set_i_i_as_stream(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_stream_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_collection(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_collection_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_addable(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_addable_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_removable(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_removable_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_removable(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_settable(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_settable_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_ordered(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_ordered_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_insertable(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_insertable_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_insertable(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_set(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_settable_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_settable_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_incremental_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_incremental_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_incremental_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_reducible_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_reducible_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_reducible_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_settable_incremental_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_settable_incremental_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_incremental_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_settable_reducible_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_settable_reducible_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_reducible_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_mutable_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_mutable_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_mutable_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_ordered_set(
        const struct butterflyfish_ordered_mutable_set_i_i *const object,
        const struct butterflyfish_ordered_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_ordered_settable_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_settable_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered_settable_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_ordered_incremental_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_incremental_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered_incremental_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_ordered_reducible_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_reducible_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered_reducible_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_ordered_settable_incremental_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_settable_incremental_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered_settable_incremental_set(object, out);
}

int butterflyfish_ordered_mutable_set_i_i_as_ordered_settable_reducible_set(
        struct butterflyfish_ordered_mutable_set_i_i *const object,
        struct butterflyfish_ordered_settable_reducible_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_ordered_settable_reducible_set(object, out);
}
