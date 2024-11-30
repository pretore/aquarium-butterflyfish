#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \\
    (*(struct butterflyfish_incremental_map_$t$ **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_$t$ **) x)
#define INVOKE_MAP(x)           (*(struct butterflyfish_map_$t$ **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_$t$ **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_$t$ **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_$t$ **) x)

static inline int
as_addable(struct butterflyfish_incremental_map_$t$ *const object,
           struct butterflyfish_addable_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_addable(object, out);
}

static inline int
as_map(const struct butterflyfish_incremental_map_$t$ *const object,
       const struct butterflyfish_map_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_map(object, out);
}

static inline int
as_set(const struct butterflyfish_incremental_map_$t$ *const object,
       const struct butterflyfish_set_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_map_$t$ *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->as_set(map, out);
}

static inline int
as_collection(const struct butterflyfish_incremental_map_$t$ *const object,
              const struct butterflyfish_collection_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(const struct butterflyfish_incremental_map_$t$ *const object,
          const struct butterflyfish_stream_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_$t$ -

int butterflyfish_incremental_map_$t$_first(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_incremental_map_$t$_next(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_$t$ -

int butterflyfish_incremental_map_$t$_count(
        const struct butterflyfish_incremental_map_$t$ *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_incremental_map_$t$_last(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_incremental_map_$t$_prev(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark set_$t$ -

int butterflyfish_incremental_map_$t$_contains(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $v$const entry,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, entry, out);
}

int butterflyfish_incremental_map_$t$_contains_all(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_incremental_map_$t$_get(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $v$const entry,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, entry, out);
}

#pragma mark map_$t$ -

int butterflyfish_incremental_map_$t$_contains_key(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $mkv$const key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_$t$ *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_key(map, key, out);
}

int butterflyfish_incremental_map_$t$_contains_value(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $mvv$const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_$t$ *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_value(map, value, out);
}

int butterflyfish_incremental_map_$t$_contains_all_keys(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_stream_$mkt$ *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_$t$ *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_all_keys(map, other, out);
}

int butterflyfish_incremental_map_$t$_contains_all_values(
        const struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_stream_$mvt$ *other,
        bool *out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_$t$ *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->contains_all_values(map, other, out);
}

int butterflyfish_incremental_map_$t$_get_value(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $mkv$const key,
        const $mvv$*const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_$t$ *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->get_value(map, key, out);
}

int butterflyfish_incremental_map_$t$_get_entry(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const $mkv$const key,
        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_map_$t$ *map;
    seagrass_required_true(!as_map(object, &map));
    return INVOKE_MAP(map)->get_entry(map, key, out);
}

#pragma mark addable_$t$ -

int butterflyfish_incremental_map_$t$_add(
        struct butterflyfish_incremental_map_$t$ *const object,
        const $v$const entry) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_IS_NULL;
    }
    struct butterflyfish_addable_$t$ *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, entry);
}

int butterflyfish_incremental_map_$t$_add_all(
        struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_$t$ *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark incremental_map_$t$ -

int butterflyfish_incremental_map_$t$_as_stream(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_stream_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_incremental_map_$t$_as_collection(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_incremental_map_$t$_as_set(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_set_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_incremental_map_$t$_as_addable(
        struct butterflyfish_incremental_map_$t$ *const object,
        struct butterflyfish_addable_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_incremental_map_$t$_as_map(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_map_$t$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    return as_map(object, out);
}

int butterflyfish_incremental_map_$t$_add_value(
        struct butterflyfish_incremental_map_$t$ *const object,
        const $mkv$const key,
        const $mvv$const value) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_NULL;
    }
    return INVOKE(object)->add_value(object, key, value);
}

int butterflyfish_incremental_map_$t$_keys(
        struct butterflyfish_incremental_map_$t$ *const object,
        struct butterflyfish_incremental_set_$mkt$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->keys(object, out);
}

int butterflyfish_incremental_map_$t$_values(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_ordered_list_$mvt$ **const out) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL;
    }
    return INVOKE(object)->values(object, out);
}
