#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x)               (*(struct butterflyfish_map_i_i **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_i_i **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_i_i **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_i_i **) x)

static inline int
as_set(const struct butterflyfish_map_i_i *const object,
       const struct butterflyfish_set_i_i **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_set(object, out);
}

static inline int
as_collection(const struct butterflyfish_map_i_i *const object,
              const struct butterflyfish_collection_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(const struct butterflyfish_map_i_i *const object,
          const struct butterflyfish_stream_i_i **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_i_i -

int butterflyfish_map_i_i_first(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_map_i_i_next(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_i_i *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_i_i -

int butterflyfish_map_i_i_count(
        const struct butterflyfish_map_i_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_map_i_i_last(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_map_i_i_prev(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const item,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_i_i *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark set_i_i -

int butterflyfish_map_i_i_contains(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const entry,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, entry, out);
}

int butterflyfish_map_i_i_contains_all(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_map_i_i_get(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_map_i_i_entry *const entry,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_i_i *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, entry, out);
}

#pragma mark map_i_i -

int butterflyfish_map_i_i_as_stream(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_map_i_i_as_collection(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_collection_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_map_i_i_as_set(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_set_i_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_map_i_i_contains_key(
        const struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->contains_key(object, key, out);
}

int butterflyfish_map_i_i_contains_value(
        const struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->contains_value(object, value, out);
}

int butterflyfish_map_i_i_contains_all_keys(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->contains_all_keys(object, other, out);
}

int butterflyfish_map_i_i_contains_all_values(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_stream_i *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->contains_all_values(object, other, out);
}

int butterflyfish_map_i_i_get_value(
        const struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->get_value(object, key, out);
}

int butterflyfish_map_i_i_get_entry(
        const struct butterflyfish_map_i_i *const object,
        const struct sea_turtle_integer *const key,
        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->get_entry(object, key, out);
}

int butterflyfish_map_i_i_keys(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->keys(object, out);
}

int butterflyfish_map_i_i_values(
        const struct butterflyfish_map_i_i *const object,
        const struct butterflyfish_ordered_list_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->values(object, out);
}
