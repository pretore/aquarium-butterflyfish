#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_sorted_map_ni_ni **) object)

#pragma mark stream_ni_ni -

int butterflyfish_sorted_map_ni_ni_first(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->first
            ? INVOKABLE->first
            : INVOKABLE->ordered_map_ni_ni
                    .map_ni_ni
                    .collection_ni_ni
                    .stream_ni_ni
                    .first)(object, out);
}

int butterflyfish_sorted_map_ni_ni_next(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni *const entry,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->next
            ? INVOKABLE->next
            : INVOKABLE->ordered_map_ni_ni
                    .map_ni_ni
                    .collection_ni_ni
                    .stream_ni_ni
                    .next)(object, entry, out);
}

#pragma mark collection_ni_ni -

int butterflyfish_sorted_map_ni_ni_count(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .collection_ni_ni
            .count(object, out);
}

int butterflyfish_sorted_map_ni_ni_last(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->last
            ? INVOKABLE->last
            : INVOKABLE->ordered_map_ni_ni
                    .map_ni_ni
                    .collection_ni_ni
                    .last)(object, out);
}

int butterflyfish_sorted_map_ni_ni_prev(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni *const entry,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return (INVOKABLE->prev
            ? INVOKABLE->prev
            : INVOKABLE->ordered_map_ni_ni
                    .map_ni_ni
                    .collection_ni_ni
                    .prev)(object, entry, out);
}

#pragma mark map_ni_ni -

int butterflyfish_sorted_map_ni_ni_remove_entry(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_map_entry_ni_ni *const entry) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!entry) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .remove_entry(object, entry);
}

int butterflyfish_sorted_map_ni_ni_remove_all_entries(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .remove_all_entries(object, other);
}

int butterflyfish_sorted_map_ni_ni_add(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .add(object, key, value);
}

int butterflyfish_sorted_map_ni_ni_put(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .put(object, key, value);
}

int butterflyfish_sorted_map_ni_ni_replace(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .replace(object, key, value);
}

int butterflyfish_sorted_map_ni_ni_remove(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .remove(object, key);
}

int butterflyfish_sorted_map_ni_ni_add_all(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .add_all(object, other);
}

int butterflyfish_sorted_map_ni_ni_put_all(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .put_all(object, other);
}

int butterflyfish_sorted_map_ni_ni_replace_all(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .replace_all(object, other);
}

int butterflyfish_sorted_map_ni_ni_remove_all(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .remove_all(object, other);
}

int butterflyfish_sorted_map_ni_ni_retain_all(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .retain_all(object, other);
}

int butterflyfish_sorted_map_ni_ni_merge(
        struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_stream_ni_ni *const other,
        int (*const function)(
                const uintmax_t,
                const uintmax_t,
                uintmax_t *)) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    if (!function) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_FUNCTION_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .merge(object, other, function);
}

int butterflyfish_sorted_map_ni_ni_contains_key(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .contains_key(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_contains_all_keys(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const struct butterflyfish_stream_ni *const other,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .contains_all_keys(object, other, out);
}

int butterflyfish_sorted_map_ni_ni_get(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .get(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_get_entry(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .get_entry(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_values(
        struct butterflyfish_sorted_map_ni_ni *const object,
        struct butterflyfish_reducible_list_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ordered_map_ni_ni
            .map_ni_ni
            .values(object, out);
}

#pragma mark ordered_map_ni_ni -
#pragma mark sorted_map_ni_ni -

int butterflyfish_sorted_map_ni_ni_keys(
        struct butterflyfish_sorted_map_ni_ni *const object,
        struct butterflyfish_sorted_set_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->keys(object, out);
}

int butterflyfish_sorted_map_ni_ni_ceiling(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ceiling(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_floor(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->floor(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_higher(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->higher(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_lower(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->lower(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_ceiling_entry(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->ceiling_entry(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_floor_entry(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->floor_entry(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_lower_entry(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->lower_entry(object, key, out);
}

int butterflyfish_sorted_map_ni_ni_higher_entry(
        const struct butterflyfish_sorted_map_ni_ni *const object,
        const uintmax_t key,
        const struct butterflyfish_map_entry_ni_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->higher_entry(object, key, out);
}
