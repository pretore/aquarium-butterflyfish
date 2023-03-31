#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_sorted_map_p_p **) object)

#pragma mark stream_p_p -

int butterflyfish_sorted_map_p_p_first(
        const struct butterflyfish_sorted_map_p_p *const object,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .collection_p_p
            .stream_p_p
            .first(object, out);
}

int butterflyfish_sorted_map_p_p_next(
        const struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_map_entry_p_p *const entry,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .collection_p_p
            .stream_p_p
            .next(object, entry, out);
}

#pragma mark collection_p_p -

int butterflyfish_sorted_map_p_p_count(
        const struct butterflyfish_sorted_map_p_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .collection_p_p
            .count(object, out);
}

int butterflyfish_sorted_map_p_p_last(
        const struct butterflyfish_sorted_map_p_p *const object,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .collection_p_p
            .last(object, out);
}

int butterflyfish_sorted_map_p_p_prev(
        const struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_map_entry_p_p *const entry,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .collection_p_p
            .prev(object, entry, out);
}

#pragma mark map_p_p -

int butterflyfish_sorted_map_p_p_remove_entry(
        struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_map_entry_p_p *const entry) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_ENTRY_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .remove_entry(object, entry);
}

int butterflyfish_sorted_map_p_p_remove_all_entries(
        struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .remove_all_entries(object, other);
}

int butterflyfish_sorted_map_p_p_add(
        struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .add(object, key, value);
}

int butterflyfish_sorted_map_p_p_put(
        struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .put(object, key, value);
}

int butterflyfish_sorted_map_p_p_replace(
        struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .replace(object, key, value);
}

int butterflyfish_sorted_map_p_p_remove(
        struct butterflyfish_sorted_map_p_p *const object,
        const void *const key) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .remove(object, key);
}

int butterflyfish_sorted_map_p_p_add_all(
        struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .add_all(object, other);
}

int butterflyfish_sorted_map_p_p_put_all(
        struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .put_all(object, other);
}

int butterflyfish_sorted_map_p_p_replace_all(
        struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .replace_all(object, other);
}

int butterflyfish_sorted_map_p_p_remove_all(
        struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .remove_all(object, other);
}

int butterflyfish_sorted_map_p_p_retain_all(
        struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .retain_all(object, other);
}

int butterflyfish_sorted_map_p_p_merge(
        struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_stream_p_p *const other,
        int (*const function)(
                const void *,
                const void *,
                void **)) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    if (!function) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_FUNCTION_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .merge(object, other, function);
}

int butterflyfish_sorted_map_p_p_contains_key(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .contains_key(object, key, out);
}

int butterflyfish_sorted_map_p_p_contains_all_keys(
        const struct butterflyfish_sorted_map_p_p *const object,
        const struct butterflyfish_stream_p *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .contains_all_keys(object, other, out);
}

int butterflyfish_sorted_map_p_p_get(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .get(object, key, out);
}

int butterflyfish_sorted_map_p_p_get_entry(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .get_entry(object, key, out);
}

int butterflyfish_sorted_map_p_p_keys(
        struct butterflyfish_sorted_map_p_p *const object,
        struct butterflyfish_set_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .keys(object, out);
}

int butterflyfish_sorted_map_p_p_values(
        struct butterflyfish_sorted_map_p_p *const object,
        struct butterflyfish_reducible_list_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_p_p
            .map_p_p
            .values(object, out);
}

#pragma mark ordered_map_p_p -
#pragma mark sorted_map_p_p -

int butterflyfish_sorted_map_p_p_ceiling(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ceiling(object, key, out);
}

int butterflyfish_sorted_map_p_p_floor(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->floor(object, key, out);
}

int butterflyfish_sorted_map_p_p_higher(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->higher(object, key, out);
}

int butterflyfish_sorted_map_p_p_lower(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->lower(object, key, out);
}

int butterflyfish_sorted_map_p_p_ceiling_entry(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ceiling_entry(object, key, out);
}

int butterflyfish_sorted_map_p_p_floor_entry(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->floor_entry(object, key, out);
}

int butterflyfish_sorted_map_p_p_lower_entry(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->lower_entry(object, key, out);
}

int butterflyfish_sorted_map_p_p_higher_entry(
        const struct butterflyfish_sorted_map_p_p *const object,
        const void *const key,
        struct butterflyfish_map_entry_p_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_P_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->higher_entry(object, key, out);
}
