#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)  \
    (*(struct butterflyfish_settable_incremental_map_i_i **) x)
#define INVOKE_SETTABLE_MAP(x) \
    (*(struct butterflyfish_settable_map_i_i **) x)
#define INVOKE_INCREMENTAL_MAP(x) \
    (*(struct butterflyfish_incremental_map_i_i **) x)
#define INVOKE_MAP(x)           (*(struct butterflyfish_map_i_i **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_i_i **) x)
#define INVOKE_SETTABLE(x)      (*(struct butetrflyfish_settable_i_i **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_i_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i_i **) x)

static inline int
as_settable_map(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        struct butterflyfish_settable_map_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_settable_map(object, out);
}

static inline int
as_incremental_map(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        struct butterflyfish_incremental_map_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_incremental_map(object, out);
}

static inline int
as_map(const struct butterflyfish_settable_incremental_map_i_i *const object,
       const struct butterflyfish_map_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map((void *) object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)->as_map(settable_map, out);
}

static inline int
as_addable(struct butterflyfish_settable_incremental_map_i_i *const object,
           struct butterflyfish_addable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_map_i_i *incremental_map;
    seagrass_required_true(!as_incremental_map(object, &incremental_map));
    return INVOKE_INCREMENTAL_MAP(incremental_map)
        ->as_addable(incremental_map, out);
}

static inline int
as_settable(struct butterflyfish_settable_incremental_map_i_i *const object,
            struct butterflyfish_settable_i_i **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map(object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)->as_settable(settable_map, out);
}

static inline int
as_set(const struct butterflyfish_settable_incremental_map_i_i *const object,
       const struct butterflyfish_set_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->as_set(map, out);
}

static inline int
as_collection(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_collection_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_stream_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i_i -

int butterflyfish_settable_incremental_map_i_i_first(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_settable_incremental_map_i_i_next(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i_i -

int butterflyfish_settable_incremental_map_i_i_count(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_settable_incremental_map_i_i_last(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_settable_incremental_map_i_i_prev(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark set_i_i -

int butterflyfish_settable_incremental_map_i_i_contains(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const entry,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, entry, out);
}

int butterflyfish_settable_incremental_map_i_i_contains_all(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_stream_i_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_settable_incremental_map_i_i_get(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const entry,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, entry, out);
}

#pragma mark addable_i_i -

int butterflyfish_settable_incremental_map_i_i_add(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const entry) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    struct butterflyfish_addable_i_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, entry);
}

int butterflyfish_settable_incremental_map_i_i_add_all(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_stream_i_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_i_i *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark map_i_i -

int butterflyfish_settable_incremental_map_i_i_contains_key(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_key(map, key, out);
}

int butterflyfish_settable_incremental_map_i_i_contains_value(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct sea_turtle_integer *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_value(map, value, out);
}

int butterflyfish_settable_incremental_map_i_i_contains_all_keys(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_stream_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_all_keys(map, other, out);
}

int butterflyfish_settable_incremental_map_i_i_contains_all_values(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_stream_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_all_values(map, other, out);
}

int butterflyfish_settable_incremental_map_i_i_get_value(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->get_value(map, key, out);
}

int butterflyfish_settable_incremental_map_i_i_get_entry(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_i_i *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->get_entry(map, key, out);
}

#pragma mark incremental_map_i_i -

int butterflyfish_settable_incremental_map_i_i_add_value(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_incremental_map_i_i *incremental_map;
    seagrass_required_true(!as_incremental_map(object, &incremental_map));
    return INVOKE_INCREMENTAL_MAP(incremental_map)
        ->add_value(incremental_map, key, value);
}

#pragma mark settable_map_i_i -

int butterflyfish_settable_incremental_map_i_i_set_value(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map(object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)->set_value(settable_map, key, value);
}

int butterflyfish_settable_incremental_map_i_i_set_key(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map(object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)->set_key(settable_map, key, value);
}

int butterflyfish_settable_incremental_map_i_i_set_entry(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const entry,
        const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_map_i_i *settable_map;
    seagrass_required_true(!as_settable_map(object, &settable_map));
    return INVOKE_SETTABLE_MAP(settable_map)
        ->set_entry(settable_map, entry, value);
}

#pragma mark settable_incremental_map_i_i -

int butterflyfish_settable_incremental_map_i_i_as_stream(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_stream_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_settable_incremental_map_i_i_as_collection(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_collection_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_settable_incremental_map_i_i_as_set(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_settable_incremental_map_i_i_as_map(
        const struct butterflyfish_settable_incremental_map_i_i *const object,
        const struct butterflyfish_map_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_map(object, out);
}

int butterflyfish_settable_incremental_map_i_i_as_settable(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        struct butterflyfish_settable_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable(object, out);
}

int butterflyfish_settable_incremental_map_i_i_as_addable(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        struct butterflyfish_addable_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_settable_incremental_map_i_i_as_settable_map(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        struct butterflyfish_settable_map_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_settable_map(object, out);
}

int butterflyfish_settable_incremental_map_i_i_as_incremental_map(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        struct butterflyfish_incremental_map_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_incremental_map(object, out);
}

int butterflyfish_settable_incremental_map_i_i_keys(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        struct butterflyfish_settable_incremental_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->keys(object, out);
}

int butterflyfish_settable_incremental_map_i_i_values(
        struct butterflyfish_settable_incremental_map_i_i *const object,
        struct butterflyfish_ordered_settable_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->values(object, out);
}

