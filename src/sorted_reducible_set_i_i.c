#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \
    (*(struct butterflyfish_sorted_reducible_set_i_i **) x)
#define INVOKE_REDUCIBLE_SET(x) \
    (*(struct butterflyfish_reducible_set_i_i **) x)
#define INVOKE_SORTED_SET(x)    (*(struct butterflyfish_sorted_set_i_i **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_i_i **) x)
#define INVOKE_SORTED(x)        (*(struct butterflyfish_sorted_i_i **) x)
#define INVOKE_REMOVABLE(x)     (*(struct butterflyfish_removable_i_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i_i **) x)

static inline int
as_reducible_set(
        struct butterflyfish_sorted_reducible_set_i_i *const object,
        struct butterflyfish_reducible_set_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_reducible_set(object, out);
}

static inline int
as_sorted_set(const struct butterflyfish_sorted_reducible_set_i_i *const object,
              const struct butterflyfish_sorted_set_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_sorted_set(object, out);
}

static inline int
as_set(const struct butterflyfish_sorted_reducible_set_i_i *const object,
       const struct butterflyfish_set_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_reducible_set_i_i *reducible_set;
    seagrass_required_true(!as_reducible_set((void *) object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)->as_set(reducible_set, out);
}

static inline int
as_sorted(const struct butterflyfish_sorted_reducible_set_i_i *const object,
          const struct butterflyfish_sorted_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_sorted_set_i_i *sorted_set;
    seagrass_required_true(!as_sorted_set(object, &sorted_set));
    return INVOKE_SORTED_SET(sorted_set)->as_sorted(sorted_set, out);
}

static inline int
as_removable(struct butterflyfish_sorted_reducible_set_i_i *const object,
             struct butterflyfish_removable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_reducible_set_i_i *reducible_set;
    seagrass_required_true(!as_reducible_set(object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)
            ->as_removable(reducible_set, out);
}

static inline int
as_collection(const struct butterflyfish_sorted_reducible_set_i_i *const object,
              const struct butterflyfish_collection_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(const struct butterflyfish_sorted_reducible_set_i_i *const object,
          const struct butterflyfish_stream_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i_i -

int butterflyfish_sorted_reducible_set_i_i_first(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_sorted_reducible_set_i_i_next(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i_i -

int butterflyfish_sorted_reducible_set_i_i_count(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_sorted_reducible_set_i_i_last(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_sorted_reducible_set_i_i_prev(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark sorted_i_i -

int butterflyfish_sorted_reducible_set_i_i_ceiling(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->ceiling(sorted, value, out);
}

int butterflyfish_sorted_reducible_set_i_i_floor(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->floor(sorted, value, out);
}

int butterflyfish_sorted_reducible_set_i_i_higher(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->higher(sorted, value, out);
}

int butterflyfish_sorted_reducible_set_i_i_lower(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_i_i *sorted;
    seagrass_required_true(!as_sorted(object, &sorted));
    return INVOKE_SORTED(sorted)->lower(sorted, value, out);
}

#pragma mark set_i_i -

int butterflyfish_sorted_reducible_set_i_i_contains(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, value, out);
}

int butterflyfish_sorted_reducible_set_i_i_contains_all(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_sorted_reducible_set_i_i_get(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, value, out);
}

#pragma mark removable_i_i -

int butterflyfish_sorted_reducible_set_i_i_remove_item(
        struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_ITEM_IS_NULL;
    }
    struct butterflyfish_removable_i_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_item(removable, item);
}

int butterflyfish_sorted_reducible_set_i_i_remove_all_items(
        struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_removable_i_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_all_items(removable, other);
}

#pragma mark reducible_set_i_i -

int butterflyfish_sorted_reducible_set_i_i_remove(
        struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_reducible_set_i_i *reducible_set;
    seagrass_required_true(!as_reducible_set(object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)->remove(reducible_set, value);
}

int butterflyfish_sorted_reducible_set_i_i_remove_all(
        struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_reducible_set_i_i *reducible_set;
    seagrass_required_true(!as_reducible_set(object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)
            ->remove_all(reducible_set, other);
}

int butterflyfish_sorted_reducible_set_i_i_retain_all(
        struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_reducible_set_i_i *reducible_set;
    seagrass_required_true(!as_reducible_set(object, &reducible_set));
    return INVOKE_REDUCIBLE_SET(reducible_set)
            ->retain_all(reducible_set, other);
}

#pragma mark sorted_reducible_set_i_i -

int butterflyfish_sorted_reducible_set_i_i_as_stream(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_stream_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_sorted_reducible_set_i_i_as_collection(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_collection_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_sorted_reducible_set_i_i_as_sorted(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_sorted_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted(object, out);
}

int butterflyfish_sorted_reducible_set_i_i_as_set(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_sorted_reducible_set_i_i_as_removable(
        struct butterflyfish_sorted_reducible_set_i_i *const object,
        struct butterflyfish_removable_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_removable(object, out);
}

int butterflyfish_sorted_reducible_set_i_i_as_sorted_set(
        const struct butterflyfish_sorted_reducible_set_i_i *const object,
        const struct butterflyfish_sorted_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_set(object, out);
}

int butterflyfish_sorted_reducible_set_i_i_as_reducible_set(
        struct butterflyfish_sorted_reducible_set_i_i *const object,
        struct butterflyfish_reducible_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_REDUCIBLE_SET_I_I_ERROR_OUT_IS_NULL;
    }
    return as_reducible_set(object, out);
}
