#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \
    (*(struct butterflyfish_sorted_settable_reducible_map_i_i **) x)
#define INVOKE_SORTED_SETTABLE_MAP(x) \
    (*(struct butterflyfish_sorted_settable_map_i_i **) x)
#define INVOKE_SETTABLE_REDUCIBLE_MAP(x) \
    (*(struct butterflyfish_settable_reducible_map_i_i **) x)
#define INVOKE_SORTED_REDUCIBLE_MAP(x) \
    (*(struct butterflyfish_sorted_reducible_map_i_i **) x)
#define INVOKE_REDUCIBLE_MAP(x) \
    (*(struct butterflyfish_reducible_map_i_i **) x)
#define INVOKE_SETTABLE_MAP(x) \
    (*(struct butterflyfish_settable_map_i_i **) x)
#define INVOKE_SORTED_MAP(x) \
    (*(struct butterflyfish_sorted_map_i_i **) x)
#define INVOKE_MAP(x)           (*(struct butterflyfish_map_i_i **) x)
#define INVOKE_SETTABLE(x)      (*(struct butterflyfihs_settable_i_i **) x)
#define INVOKE_REMOVABLE(x)     (*(struct butterflyfish_removable_i_i **) x)
#define INVOKE_SORTED(x)        (*(struct butterflyfish_sorted_i_i **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_i_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i_i **) x)

static inline int
as_sorted_settable_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_sorted_settable_map_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_sorted_settable_map(object, out);
}

static inline int
as_settable_reducible_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_settable_reducible_map_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_settable_reducible_map(object, out);
}

static inline int
as_sorted_reducible_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_sorted_reducible_map_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_sorted_reducible_map(object, out);
}

static inline int
as_settable_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_settable_map_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_map_i_i *sorted_settable_map;
    seagrass_required_true(!as_sorted_settable_map(
            object, &sorted_settable_map));
    return INVOKE_SORTED_SETTABLE_MAP(sorted_settable_map)
            ->as_settable_map(sorted_settable_map, out);
}

static inline int
as_reducible_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_reducible_map_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_reducible_map_i_i *sorted_reducible_map;
    seagrass_required_true(!as_sorted_reducible_map(
            object, &sorted_reducible_map));
    return INVOKE_SORTED_REDUCIBLE_MAP(sorted_reducible_map)
        ->as_reducible_map(sorted_reducible_map, out);
}

static inline int
as_sorted_map(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_sorted_map_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_sorted_settable_map_i_i *sorted_settable_map;
    seagrass_required_true(!as_sorted_settable_map(
            (void *)object, &sorted_settable_map));
    return INVOKE_SORTED_SETTABLE_MAP(sorted_settable_map)
        ->as_sorted_map(sorted_settable_map, out);
}

static inline int
as_map(const struct butterflyfish_sorted_settable_reducible_map_i_i
            *const object,
       const struct butterflyfish_map_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map((void *) object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)->as_map(settable_map, out);
}

static inline int
as_removable(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_removable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_reducible_map_i_i *reducible_map;
    seagrass_required_true(!as_reducible_map((void *) object, &reducible_map));
    return INVOKE_REDUCIBLE_MAP(reducible_map)
        ->as_removable(reducible_map, out);
}

static inline int
as_settable(struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
            struct butterflyfish_settable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map(object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)->as_settable(settable_map, out);
}

static inline int
as_sorted(const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
          const struct butterflyfish_sorted_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_sorted_map_i_i *sorted_map;
    seagrass_required_true(!as_sorted_map(object, &sorted_map));
    return INVOKE_SORTED_MAP(sorted_map)->as_sorted(sorted_map, out);
}

static inline int
as_set(const struct butterflyfish_sorted_settable_reducible_map_i_i
        *const object,
       const struct butterflyfish_set_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->as_set(map, out);
}

static inline int
as_collection(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
            *const object,
        const struct butterflyfish_collection_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(const struct butterflyfish_sorted_settable_reducible_map_i_i
                  *const object,
          const struct butterflyfish_stream_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i_i -

int butterflyfish_sorted_settable_reducible_map_i_i_first(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_next(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i_i -

int butterflyfish_sorted_settable_reducible_map_i_i_count(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        uintmax_t *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_last(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_prev(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark removable_i_i -

int butterflyfish_sorted_settable_reducible_map_i_i_remove_entry(
        struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_map_i_i_entry *const entry) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    struct butterflyfish_removable_i_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_item(removable, entry);
}

int butterflyfish_sorted_settable_reducible_map_i_i_remove_all_entries(
        struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_removable_i_i *removable;
    seagrass_required_true(!as_removable(object, &removable));
    return INVOKE_REMOVABLE(removable)->remove_all_items(removable, other);
}

#pragma mark set_i_i -

int butterflyfish_sorted_settable_reducible_map_i_i_contains(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_map_i_i_entry *const entry,
        bool *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, entry, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_contains_all(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_stream_i_i *const other,
        bool *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_get(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_map_i_i_entry *const entry,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, entry, out);
}

#pragma mark map_i_i -

int butterflyfish_sorted_settable_reducible_map_i_i_contains_key(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct sea_turtle_integer *const key,
        bool *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_key(map, key, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_contains_value(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct sea_turtle_integer *const value,
        bool *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_value(map, value, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_contains_all_keys(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_stream_i *const other,
        bool *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_all_keys(map, other, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_contains_all_values(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_stream_i *const other,
        bool *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_all_values(map, other, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_get_value(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->get_value(map, key, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_get_entry(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct sea_turtle_integer *const key,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->get_entry(map, key, out);
}

#pragma mark settable_map_i_i -

int butterflyfish_sorted_settable_reducible_map_i_i_set_value(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map(object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)
        ->set_value(settable_map, key, value);
}

int butterflyfish_sorted_settable_reducible_map_i_i_set_key(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map(object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)
            ->set_key(settable_map, key, value);
}

int butterflyfish_sorted_settable_reducible_map_i_i_set_entry(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const entry,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map(object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)
            ->set_entry(settable_map, entry, value);
}

#pragma mark reducible_map_i_i -

int butterflyfish_sorted_settable_reducible_map_i_i_remove(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        const struct sea_turtle_integer *const key) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    struct butterflyfish_reducible_map_i_i *reducible_map;
    seagrass_required_true(!as_reducible_map(object, &reducible_map));
    return INVOKE_REDUCIBLE_MAP(reducible_map)->remove(reducible_map, key);
}

int butterflyfish_sorted_settable_reducible_map_i_i_remove_all(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_reducible_map_i_i *reducible_map;
    seagrass_required_true(!as_reducible_map(object, &reducible_map));
    return INVOKE_REDUCIBLE_MAP(reducible_map)
        ->remove_all(reducible_map, other);
}

int butterflyfish_sorted_settable_reducible_map_i_i_retain_all(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_reducible_map_i_i *reducible_map;
    seagrass_required_true(!as_reducible_map(object, &reducible_map));
    return INVOKE_REDUCIBLE_MAP(reducible_map)
        ->retain_all(reducible_map, other);
}

#pragma mark sorted_map_i_i -

int butterflyfish_sorted_settable_reducible_map_i_i_ceiling(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct sea_turtle_integer *const key,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_map_i_i *sorted_map;
    seagrass_required_true(!as_sorted_map(object, &sorted_map));
    return INVOKE_SORTED_MAP(sorted_map)->ceiling(sorted_map, key, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_floor(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct sea_turtle_integer *const key,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_map_i_i *sorted_map;
    seagrass_required_true(!as_sorted_map(object, &sorted_map));
    return INVOKE_SORTED_MAP(sorted_map)->floor(sorted_map, key, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_higher(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct sea_turtle_integer *const key,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_map_i_i *sorted_map;
    seagrass_required_true(!as_sorted_map(object, &sorted_map));
    return INVOKE_SORTED_MAP(sorted_map)->higher(sorted_map, key, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_lower(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct sea_turtle_integer *const key,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_sorted_map_i_i *sorted_map;
    seagrass_required_true(!as_sorted_map(object, &sorted_map));
    return INVOKE_SORTED_MAP(sorted_map)->lower(sorted_map, key, out);
}

#pragma mark sorted_settable_reducible_map_i_i -

int butterflyfish_sorted_settable_reducible_map_i_i_as_stream(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_stream_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_collection(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_collection_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_set(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_set_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_removable(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_removable_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_removable(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_sorted(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_sorted_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_settable(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_settable_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_map(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_map_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_map(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_sorted_map(
        const struct butterflyfish_sorted_settable_reducible_map_i_i
                *const object,
        const struct butterflyfish_sorted_map_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_map(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_settable_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_settable_map_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_map(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_reducible_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_reducible_map_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_reducible_map(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_sorted_settable_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_sorted_settable_map_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_settable_map(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_settable_reducible_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_settable_reducible_map_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_reducible_map(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_as_sorted_reducible_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_sorted_reducible_map_i_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_sorted_reducible_map(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_keys(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_sorted_settable_reducible_set_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->keys(object, out);
}

int butterflyfish_sorted_settable_reducible_map_i_i_values(
        struct butterflyfish_sorted_settable_reducible_map_i_i *const object,
        struct butterflyfish_ordered_settable_reducible_list_i **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->values(object, out);
}
