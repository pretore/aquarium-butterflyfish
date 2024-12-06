#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <test/cmocka.h>

struct object {
    const struct butterflyfish_ordered_mutable_map_$t$ *const
            ordered_mutable_map_$t$;
    const struct butterflyfish_ordered_settable_incremental_map_$t$ *const
            ordered_settable_incremental_map_$t$;
    const struct butterflyfish_ordered_settable_reducible_map_$t$ *const
            ordered_settable_reducible_map_$t$;
    const struct butterflyfish_mutable_map_$t$ *const mutable_map_$t$;
    const struct butterflyfish_settable_incremental_map_$t$ *const
            settable_incremental_map_$t$;
    const struct butterflyfish_settable_reducible_map_$t$ *const
            settable_reducible_map_$t$;
    const struct butterflyfish_ordered_settable_map_$t$ *const
            ordered_settable_map_$t$;
    const struct butterflyfish_ordered_incremental_map_$t$ *const
            ordered_incremental_map_$t$;
    const struct butterflyfish_ordered_reducible_map_$t$ *const
            ordered_reducible_map_$t$;
    const struct butterflyfish_ordered_map_$t$ *const ordered_map_$t$;
    const struct butterflyfish_settable_map_$t$ *const settable_map_$t$;
    const struct butterflyfish_incremental_map_$t$ *const incremental_map_$t$;
    const struct butterflyfish_reducible_map_$t$ *const reducible_map_$t$;
    const struct butterflyfish_map_$t$ *const map_$t$;
    const struct butterflyfish_insertable_$t$ *const insertable_$t$;
    const struct butterflyfish_ordered_$t$ *const ordered_$t$;
    const struct butterflyfish_addable_$t$ *const addable_$t$;
    const struct butterflyfish_removable_$t$ *const removable_$t$;
    const struct butterflyfish_settable_$t$ *const settable_$t$;
    const struct butterflyfish_set_$t$ *const set_$t$;
    const struct butterflyfish_collection_$t$ *const collection_$t$;
    const struct butterflyfish_stream_$t$ *const stream_$t$;
};

static int stream_first(const struct butterflyfish_stream_$t$ *const object,
                        const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int stream_next(const struct butterflyfish_stream_$t$ *const object,
                       const $v$const item,
                       const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_stream_$t$ stream_$t$ = {
        .first = stream_first,
        .next = stream_next
};

static int
collection_as_stream(const struct butterflyfish_collection_$t$ *const object,
                     const struct butterflyfish_stream_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, collection_$t$,
            stream_$t$);
    return 0;
}

static int
collection_last(const struct butterflyfish_collection_$t$ *const object,
                const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
collection_prev(const struct butterflyfish_collection_$t$ *const object,
                const $v$const item,
                const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static int
collection_count(const struct butterflyfish_collection_$t$ *const object,
                 uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_$t$ collection_$t$ = {
        .as_stream = collection_as_stream,
        .last = collection_last,
        .prev = collection_prev,
        .count = collection_count,
};

static int
addable_as_collection(const struct butterflyfish_addable_$t$ *const object,
                      const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, addable_$t$,
            collection_$t$);
    return 0;
}

static int
addable_add(struct butterflyfish_addable_$t$ *const object,
            const $v$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static int
addable_add_all(struct butterflyfish_addable_$t$ *const object,
                const struct butterflyfish_stream_$t$ *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_addable_$t$ addable_$t$ = {
        .as_collection = addable_as_collection,
        .add = addable_add,
        .add_all = addable_add_all,
};

static int
ordered_as_collection(const struct butterflyfish_ordered_$t$ *const object,
                      const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_$t$,
                              collection_$t$);
    return 0;
}

const struct butterflyfish_ordered_$t$ ordered_$t$ = {
        .as_collection = ordered_as_collection,
};

static int
insertable_as_ordered(const struct butterflyfish_insertable_$t$ *const object,
                      const struct butterflyfish_ordered_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, insertable_$t$, ordered_$t$);
    return 0;
}

static int
insertable_insert(struct butterflyfish_insertable_$t$ *const object,
                  const $v$const item,
                  const $v$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

static int
insertable_insert_all(struct butterflyfish_insertable_$t$ *const object,
                      const $v$const item,
                      const struct butterflyfish_stream_$t$ *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_insertable_$t$ insertable_$t$ = {
        .as_ordered = insertable_as_ordered,
        .insert = insertable_insert,
        .insert_all = insertable_insert_all,
};

static int
removable_as_collection(
        const struct butterflyfish_removable_$t$ *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, removable_$t$,
            collection_$t$);
    return 0;
}

static int
removable_remove_item(struct butterflyfish_removable_$t$ *const object,
                      const $v$const item) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return mock();
}

static int
removable_remove_all_items(
        struct butterflyfish_removable_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_removable_$t$ removable_$t$ = {
        .as_collection = removable_as_collection,
        .remove_item = removable_remove_item,
        .remove_all_items = removable_remove_all_items,
};

static int
settable_as_collection(
        const struct butterflyfish_settable_$t$ *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_$t$,
            collection_$t$);
    return 0;
}

static int
settable_set_item(struct butterflyfish_settable_$t$ *const object,
                  const $v$const item,
                  const $v$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_$t$ settable_$t$ = {
        .as_collection = settable_as_collection,
        .set_item = settable_set_item,
};

static int
set_as_collection(const struct butterflyfish_set_$t$ *const object,
                  const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, set_$t$, collection_$t$);
    return 0;
}

static int set_contains(const struct butterflyfish_set_$t$ *const object,
                        const $v$const value,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int set_contains_all(const struct butterflyfish_set_$t$ *const object,
                            const struct butterflyfish_stream_$t$ *const other,
                            bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static int set_get(const struct butterflyfish_set_$t$ *const object,
                   const $v$const value,
                   const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_set_$t$ set_$t$ = {
        .as_collection = set_as_collection,
        .contains = set_contains,
        .contains_all = set_contains_all,
        .get = set_get,
};

static int map_as_set(const struct butterflyfish_map_$t$ *const object,
                      const struct butterflyfish_set_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, map_$t$, set_$t$);
    return 0;
}

static int
map_contains_key(const struct butterflyfish_map_$t$ *const object,
                 const $mkv$const key,
                 bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static int
map_contains_value(const struct butterflyfish_map_$t$ *const object,
                   const $mvv$const value,
                   bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int
map_contains_all_keys(const struct butterflyfish_map_$t$ *const object,
                      const struct butterflyfish_stream_$mkt$ *const other,
                      bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static int
map_contains_all_values(const struct butterflyfish_map_$t$ *const object,
                        const struct butterflyfish_stream_$mvt$ *const other,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static int map_get_value(const struct butterflyfish_map_$t$ *const object,
                         const $mkv$const key,
                         const $mvv$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static int
map_get_entry(const struct butterflyfish_map_$t$ *const object,
              const $mkv$const key,
              const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static int map_keys(const struct butterflyfish_map_$t$ *const object,
                    const struct butterflyfish_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int map_values(const struct butterflyfish_map_$t$ *const object,
                      const struct butterflyfish_ordered_list_$mvt$ **const
                              out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_map_$t$ map_$t$ = {
        .as_set = map_as_set,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .contains_all_keys = map_contains_all_keys,
        .contains_all_values = map_contains_all_values,
        .get_value = map_get_value,
        .get_entry = map_get_entry,
        .keys = map_keys,
        .values = map_values,
};

static int
ordered_map_as_map(const struct butterflyfish_ordered_map_$t$ *const object,
                   const struct butterflyfish_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_map_$t$,
                              map_$t$);
    return 0;
}

static int
ordered_map_as_ordered(
        const struct butterflyfish_ordered_map_$t$ *const object,
        const struct butterflyfish_ordered_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_map_$t$,
                              ordered_$t$);
    return 0;
}

static int
ordered_map_keys(const struct butterflyfish_ordered_map_$t$ *const object,
                 const struct butterflyfish_ordered_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
ordered_map_values(const struct butterflyfish_ordered_map_$t$ *const object,
                   const struct butterflyfish_ordered_list_$mvt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_ordered_map_$t$ ordered_map_$t$ = {
        .as_map = ordered_map_as_map,
        .as_ordered = ordered_map_as_ordered,
        .keys = ordered_map_keys,
        .values = ordered_map_values,
};

static int
incremental_map_as_map(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_map_$t$,
                              map_$t$);
    return 0;
}

static int
incremental_map_as_addable(
        struct butterflyfish_incremental_map_$t$ *const object,
        struct butterflyfish_addable_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_map_$t$,
                              addable_$t$);
    return 0;
}

static int
incremental_map_add_value(
        struct butterflyfish_incremental_map_$t$ *const object,
        const $mkv$const key,
        const $mvv$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(value);
    return mock();
}

static int
incremental_map_keys(
        struct butterflyfish_incremental_map_$t$ *const object,
        struct butterflyfish_incremental_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
incremental_map_values(
        const struct butterflyfish_incremental_map_$t$ *const object,
        const struct butterflyfish_ordered_list_$mvt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_incremental_map_$t$ incremental_map_$t$ = {
        .as_map = incremental_map_as_map,
        .as_addable = incremental_map_as_addable,
        .add_value = incremental_map_add_value,
        .keys = incremental_map_keys,
        .values = incremental_map_values,
};

static int
reducible_map_as_map(
        const struct butterflyfish_reducible_map_$t$ *const object,
        const struct butterflyfish_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_map_$t$,
                              map_$t$);
    return 0;
}

static int
reducible_map_as_removable(struct butterflyfish_reducible_map_$t$ *const object,
                           struct butterflyfish_removable_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_map_$t$,
                              removable_$t$);
    return 0;
}

static int
reducible_map_remove(struct butterflyfish_reducible_map_$t$ *const object,
                     const $mkv$const key) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    return mock();
}

static int
reducible_map_remove_all(struct butterflyfish_reducible_map_$t$ *const object,
                         const struct butterflyfish_stream_$mkt$ *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static int
reducible_map_retain_all(struct butterflyfish_reducible_map_$t$ *const object,
                         const struct butterflyfish_stream_$mkt$ *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static int
reducible_map_keys(struct butterflyfish_reducible_map_$t$ *const object,
                   struct butterflyfish_reducible_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
reducible_map_values(struct butterflyfish_reducible_map_$t$ *const object,
                     struct butterflyfish_ordered_reducible_list_$mvt$
                             **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_reducible_map_$t$ reducible_map_$t$ = {
        .as_map = reducible_map_as_map,
        .as_removable = reducible_map_as_removable,
        .remove = reducible_map_remove,
        .remove_all = reducible_map_remove_all,
        .retain_all = reducible_map_retain_all,
        .keys = reducible_map_keys,
        .values = reducible_map_values,
};

static int
settable_map_as_map(const struct butterflyfish_settable_map_$t$ *const object,
                    const struct butterflyfish_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_map_$t$,
            map_$t$);
    return 0;
}

static int
settable_map_as_settable(struct butterflyfish_settable_map_$t$ *const object,
                         struct butterflyfish_settable_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_map_$t$,
                              settable_$t$);
    return 0;
}

static int
settable_map_set_value(struct butterflyfish_settable_map_$t$ *const object,
                       const $mkv$const key,
                       const $mvv$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(value);
    return mock();
}

static int
settable_map_set_key(struct butterflyfish_settable_map_$t$ *const object,
                     const $mkv$const key,
                     const $mkv$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(value);
    return mock();
}

static int
settable_map_set_entry(struct butterflyfish_settable_map_$t$ *const object,
                       const $v$const entry,
                       const $v$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(entry);
    assert_non_null(value);
    return mock();
}

static int
settable_map_keys(struct butterflyfish_settable_map_$t$ *const object,
                  struct butterflyfish_settable_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
settable_map_values(struct butterflyfish_settable_map_$t$ *const object,
                    struct butterflyfish_ordered_settable_list_$mvt$ **const
                            out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_settable_map_$t$ settable_map_$t$ = {
        .as_map = settable_map_as_map,
        .as_settable = settable_map_as_settable,
        .set_value = settable_map_set_value,
        .set_key = settable_map_set_key,
        .set_entry = settable_map_set_entry,
        .keys = settable_map_keys,
        .values = settable_map_values,
};

static int
ordered_settable_map_as_ordered_map(
        const struct butterflyfish_ordered_settable_map_$t$ *const object,
        const struct butterflyfish_ordered_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_settable_map_$t$,
            ordered_map_$t$);
    return 0;
}

static int
ordered_settable_map_as_settable_map(
        struct butterflyfish_ordered_settable_map_$t$ *const object,
        struct butterflyfish_settable_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_settable_map_$t$,
            settable_map_$t$);
    return 0;
}

static int
ordered_settable_map_keys(
        struct butterflyfish_ordered_settable_map_$t$ *const object,
        struct butterflyfish_ordered_settable_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
ordered_settable_map_values(
        struct butterflyfish_ordered_settable_map_$t$ *const object,
        struct butterflyfish_ordered_settable_list_$mvt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct
butterflyfish_ordered_settable_map_$t$ ordered_settable_map_$t$ = {
        .as_ordered_map = ordered_settable_map_as_ordered_map,
        .as_settable_map = ordered_settable_map_as_settable_map,
        .keys = ordered_settable_map_keys,
        .values = ordered_settable_map_values
};

static int
ordered_incremental_map_as_ordered_map(
        const struct butterflyfish_ordered_incremental_map_$t$ *const object,
        const struct butterflyfish_ordered_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_incremental_map_$t$,
            ordered_map_$t$);
    return 0;
}

static int
ordered_incremental_map_as_incremental_map(
        struct butterflyfish_ordered_incremental_map_$t$ *const object,
        struct butterflyfish_incremental_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_incremental_map_$t$,
                              incremental_map_$t$);
    return 0;
}

static int
ordered_incremental_map_as_insertable(
        struct butterflyfish_ordered_incremental_map_$t$ *const object,
        struct butterflyfish_insertable_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_incremental_map_$t$,
                              insertable_$t$);
    return 0;
}

static int
ordered_incremental_map_keys(
        struct butterflyfish_ordered_incremental_map_$t$ *const object,
        struct butterflyfish_ordered_incremental_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
ordered_incremental_map_values(
        const struct butterflyfish_ordered_incremental_map_$t$ *const object,
        const struct butterflyfish_ordered_list_$mvt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct
butterflyfish_ordered_incremental_map_$t$ ordered_incremental_map_$t$ = {
        .as_ordered_map = ordered_incremental_map_as_ordered_map,
        .as_incremental_map = ordered_incremental_map_as_incremental_map,
        .as_insertable = ordered_incremental_map_as_insertable,
        .keys = ordered_incremental_map_keys,
        .values = ordered_incremental_map_values,
};

static int
ordered_reducible_map_as_ordered_map(
        const struct butterflyfish_ordered_reducible_map_$t$ *const object,
        const struct butterflyfish_ordered_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_reducible_map_$t$,
                              ordered_map_$t$);
    return 0;
}

static int
ordered_reducible_map_as_reducible_map(
        struct butterflyfish_ordered_reducible_map_$t$ *const object,
        struct butterflyfish_reducible_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_reducible_map_$t$,
                              reducible_map_$t$);
    return 0;
}

static int
ordered_reducible_map_keys(
        struct butterflyfish_ordered_reducible_map_$t$ *const object,
        struct butterflyfish_ordered_reducible_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
ordered_reducible_map_values(
        struct butterflyfish_ordered_reducible_map_$t$ *const object,
        struct butterflyfish_ordered_reducible_list_$mvt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct
butterflyfish_ordered_reducible_map_$t$ ordered_reducible_map_$t$ = {
        .as_ordered_map = ordered_reducible_map_as_ordered_map,
        .as_reducible_map = ordered_reducible_map_as_reducible_map,
        .keys = ordered_reducible_map_keys,
        .values = ordered_reducible_map_values,
};

static int
settable_incremental_map_as_settable_map(
        struct butterflyfish_settable_incremental_map_$t$ *const object,
        struct butterflyfish_settable_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            settable_incremental_map_$t$, settable_map_$t$);
    return 0;
}

static int
settable_incremental_map_as_incremental_map(
        struct butterflyfish_settable_incremental_map_$t$ *const object,
        struct butterflyfish_incremental_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            settable_incremental_map_$t$, incremental_map_$t$);
    return 0;
}

static int
settable_incremental_map_keys(
        struct butterflyfish_settable_incremental_map_$t$ *const object,
        struct butterflyfish_settable_incremental_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
settable_incremental_map_values(
        struct butterflyfish_settable_incremental_map_$t$ *const object,
        struct butterflyfish_ordered_settable_list_$mvt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct
butterflyfish_settable_incremental_map_$t$ settable_incremental_map_$t$ = {
        .as_settable_map = settable_incremental_map_as_settable_map,
        .as_incremental_map = settable_incremental_map_as_incremental_map,
        .keys = settable_incremental_map_keys,
        .values = settable_incremental_map_values,
};

static int
settable_reducible_map_as_settable_map(
        struct butterflyfish_settable_reducible_map_$t$ *const object,
        struct butterflyfish_settable_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            settable_reducible_map_$t$, settable_map_$t$);
    return 0;
}

static int
settable_reducible_map_as_reducible_map(
        struct butterflyfish_settable_reducible_map_$t$ *const object,
        struct butterflyfish_reducible_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            settable_reducible_map_$t$, reducible_map_$t$);
    return 0;
}

static int
settable_reducible_map_keys(
        struct butterflyfish_settable_reducible_map_$t$ *const object,
        struct butterflyfish_settable_reducible_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
settable_reducible_map_values(
        struct butterflyfish_settable_reducible_map_$t$ *const object,
        struct butterflyfish_ordered_settable_reducible_list_$mvt$ **const
                out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct
butterflyfish_settable_reducible_map_$t$ settable_reducible_map_$t$ = {
        .as_settable_map = settable_reducible_map_as_settable_map,
        .as_reducible_map = settable_reducible_map_as_reducible_map,
        .keys = settable_reducible_map_keys,
        .values = settable_reducible_map_values,
};

static int
mutable_map_as_settable_reducible_map(
        struct butterflyfish_mutable_map_$t$ *const object,
        struct butterflyfish_settable_reducible_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              mutable_map_$t$, settable_reducible_map_$t$);
    return 0;
}

static int
mutable_map_as_settable_incremental_map(
        struct butterflyfish_mutable_map_$t$ *const object,
        struct butterflyfish_settable_incremental_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              mutable_map_$t$, settable_incremental_map_$t$);
    return 0;
}

static int
mutable_map_keys(struct butterflyfish_mutable_map_$t$ *const object,
                 struct butterflyfish_mutable_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
mutable_map_values(
        struct butterflyfish_mutable_map_$t$ *const object,
        struct butterflyfish_ordered_settable_reducible_list_$mvt$ **const
                out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_mutable_map_$t$ mutable_map_$t$ = {
        .as_settable_reducible_map = mutable_map_as_settable_reducible_map,
        .as_settable_incremental_map = mutable_map_as_settable_incremental_map,
        .keys = mutable_map_keys,
        .values = mutable_map_values,
};

static int
ordered_settable_reducible_map_as_ordered_reducible_map(
        struct butterflyfish_ordered_settable_reducible_map_$t$ *const object,
        struct butterflyfish_ordered_reducible_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_settable_reducible_map_$t$,
            ordered_reducible_map_$t$);
    return 0;
}

static int
ordered_settable_reducible_map_as_settable_reducible_map(
        struct butterflyfish_ordered_settable_reducible_map_$t$ *const object,
        struct butterflyfish_settable_reducible_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_settable_reducible_map_$t$,
            settable_reducible_map_$t$);
    return 0;
}

static int
ordered_settable_reducible_map_as_ordered_settable_map(
        struct butterflyfish_ordered_settable_reducible_map_$t$ *const object,
        struct butterflyfish_ordered_settable_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_settable_reducible_map_$t$,
            ordered_settable_map_$t$);
    return 0;
}

static int
ordered_settable_reducible_map_keys(
        struct butterflyfish_ordered_settable_reducible_map_$t$ *const object,
        struct butterflyfish_ordered_settable_reducible_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
ordered_settable_reducible_map_values(
        struct butterflyfish_ordered_settable_reducible_map_$t$ *const object,
        struct butterflyfish_ordered_settable_reducible_list_$mvt$ **const
                out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct
butterflyfish_ordered_settable_reducible_map_$t$
ordered_settable_reducible_map_$t$ = {
        .as_ordered_reducible_map =
                ordered_settable_reducible_map_as_ordered_reducible_map,
        .as_settable_reducible_map =
                ordered_settable_reducible_map_as_settable_reducible_map,
        .as_ordered_settable_map =
                ordered_settable_reducible_map_as_ordered_settable_map,
        .keys = ordered_settable_reducible_map_keys,
        .values = ordered_settable_reducible_map_values,
};

static int
ordered_settable_incremental_map_as_settable_incremental_map(
        struct butterflyfish_ordered_settable_incremental_map_$t$
                *const object,
        struct butterflyfish_settable_incremental_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_settable_incremental_map_$t$,
            settable_incremental_map_$t$);
    return 0;
}

static int
ordered_settable_incremental_map_as_ordered_incremental_map(
        struct butterflyfish_ordered_settable_incremental_map_$t$
                *const object,
        struct butterflyfish_ordered_incremental_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_settable_incremental_map_$t$,
            ordered_incremental_map_$t$);
    return 0;
}

static int
ordered_settable_incremental_map_as_ordered_settable_map(
        struct butterflyfish_ordered_settable_incremental_map_$t$
                *const object,
        struct butterflyfish_ordered_settable_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_settable_incremental_map_$t$,
            ordered_settable_map_$t$);
    return 0;
}

static int
ordered_settable_incremental_map_keys(
        struct butterflyfish_ordered_settable_incremental_map_$t$ *const object,
        struct butterflyfish_ordered_settable_incremental_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
ordered_settable_incremental_map_values(
        struct butterflyfish_ordered_settable_incremental_map_$t$ *const object,
        struct butterflyfish_ordered_settable_list_$mvt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct
butterflyfish_ordered_settable_incremental_map_$t$
ordered_settable_incremental_map_$t$ = {
        .as_settable_incremental_map =
                ordered_settable_incremental_map_as_settable_incremental_map,
        .as_ordered_incremental_map =
                ordered_settable_incremental_map_as_ordered_incremental_map,
        .as_ordered_settable_map =
                ordered_settable_incremental_map_as_ordered_settable_map,
        .keys = ordered_settable_incremental_map_keys,
        .values = ordered_settable_incremental_map_values,
};

static int
ordered_mutable_map_as_ordered_settable_incremental_map(
        struct butterflyfish_ordered_mutable_map_$t$ *const object,
        struct butterflyfish_ordered_settable_incremental_map_$t$
                **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_mutable_map_$t$,
            ordered_settable_incremental_map_$t$);
    return 0;
}

static int
ordered_mutable_map_as_ordered_settable_reducible_map(
        struct butterflyfish_ordered_mutable_map_$t$ *const object,
        struct butterflyfish_ordered_settable_reducible_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_mutable_map_$t$,
            ordered_settable_reducible_map_$t$);
    return 0;
}

static int
ordered_mutable_map_as_mutable_map(
        struct butterflyfish_ordered_mutable_map_$t$ *const object,
        struct butterflyfish_mutable_map_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            ordered_mutable_map_$t$,
            mutable_map_$t$);
    return 0;
}

static int
ordered_mutable_map_keys(
        struct butterflyfish_ordered_mutable_map_$t$ *const object,
        struct butterflyfish_ordered_mutable_set_$mkt$ **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
ordered_mutable_map_values(
        struct butterflyfish_ordered_mutable_map_$t$ *const object,
        struct butterflyfish_ordered_settable_reducible_list_$mvt$ **const
                out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

const struct
butterflyfish_ordered_mutable_map_$t$ ordered_mutable_map_$t$ = {
        .as_ordered_settable_incremental_map =
                &ordered_mutable_map_as_ordered_settable_incremental_map,
        .as_ordered_settable_reducible_map =
                &ordered_mutable_map_as_ordered_settable_reducible_map,
        .as_mutable_map = &ordered_mutable_map_as_mutable_map,
        .keys = &ordered_mutable_map_keys,
        .values = &ordered_mutable_map_values,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, stream_$t$);
    const struct butterflyfish_stream_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_stream(
            (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_$t$);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_collection(
            (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_set(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_set((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_set(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, set_$t$);
    const struct butterflyfish_set_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_set(
            (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_settable(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_settable((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_settable(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_$t$);
    struct butterflyfish_settable_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_removable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_removable(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_removable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_removable((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_removable(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, removable_$t$);
    struct butterflyfish_removable_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_removable(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_addable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_addable(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_addable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_addable((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_addable(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, addable_$t$);
    struct butterflyfish_addable_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_addable(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, map_$t$);
    const struct butterflyfish_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_ordered(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_$t$);
    const struct butterflyfish_ordered_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_insertable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_insertable(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_insertable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_insertable((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_insertable(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, insertable_$t$);
    struct butterflyfish_insertable_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_insertable(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_reducible_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_reducible_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_reducible_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_reducible_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_reducible_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, reducible_map_$t$);
    struct butterflyfish_reducible_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_incremental_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_incremental_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_incremental_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_incremental_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_incremental_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, incremental_map_$t$);
    struct butterflyfish_incremental_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_settable_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_settable_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_settable_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_map_$t$);
    struct butterflyfish_settable_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_map_$t$);
    const struct butterflyfish_ordered_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_reducible_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_reducible_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_reducible_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_reducible_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_reducible_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_reducible_map_$t$);
    struct butterflyfish_ordered_reducible_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_incremental_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_incremental_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_incremental_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_incremental_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_incremental_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_incremental_map_$t$);
    struct butterflyfish_ordered_incremental_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_settable_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_settable_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_settable_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_settable_map_$t$);
    struct butterflyfish_ordered_settable_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_reducible_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_settable_reducible_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_reducible_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_settable_reducible_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_settable_reducible_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_reducible_map_$t$);
    struct butterflyfish_settable_reducible_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_incremental_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_settable_incremental_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_incremental_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_settable_incremental_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_settable_incremental_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_incremental_map_$t$);
    struct butterflyfish_settable_incremental_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_mutable_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_mutable_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_mutable_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_mutable_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_mutable_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, mutable_map_$t$);
    struct butterflyfish_mutable_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_mutable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_settable_reducible_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_reducible_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_settable_reducible_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_reducible_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_settable_reducible_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_settable_reducible_map_$t$);
    struct butterflyfish_ordered_settable_reducible_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_settable_incremental_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_incremental_map(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_settable_incremental_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_incremental_map((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_settable_incremental_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_settable_incremental_map_$t$);
    struct butterflyfish_ordered_settable_incremental_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_addable_as_collection(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_$t$);
    struct butterflyfish_addable_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_addable(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_addable_$t$_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_as_collection(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_$t$);
    const struct butterflyfish_ordered_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_ordered_$t$_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_removable_as_collection(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_$t$);
    struct butterflyfish_removable_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_removable(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_removable_$t$_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_as_collection(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_$t$);
    struct butterflyfish_settable_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_settable_$t$_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_insertable_as_collection(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_$t$);
    struct butterflyfish_insertable_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_insertable(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_insertable_$t$_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_map_as_ordered(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_$t$);
    const struct butterflyfish_ordered_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_ordered_$t$ *out;
    assert_int_equal(butterflyfish_ordered_map_$t$_as_ordered(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_incremental_map_as_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, map_$t$);
    struct butterflyfish_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_map_$t$ *out;
    assert_int_equal(butterflyfish_incremental_map_$t$_as_map(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_reducible_map_as_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, map_$t$);
    struct butterflyfish_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_map_$t$ *out;
    assert_int_equal(butterflyfish_reducible_map_$t$_as_map(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_map_as_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, map_$t$);
    struct butterflyfish_settable_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_map_$t$ *out;
    assert_int_equal(butterflyfish_settable_map_$t$_as_map(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_incremental_map_as_ordered_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_map_$t$);
    struct butterflyfish_ordered_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_ordered_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_incremental_map_$t$_as_ordered_map(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_reducible_map_as_ordered_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_map_$t$);
    struct butterflyfish_ordered_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_ordered_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_reducible_map_$t$_as_ordered_map(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_incremental_map_as_settable_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_map_$t$);
    struct butterflyfish_settable_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_settable_map_$t$ *out;
    assert_int_equal(butterflyfish_settable_incremental_map_$t$_as_settable_map(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_incremental_map_as_incremental_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, incremental_map_$t$);
    struct butterflyfish_settable_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_incremental_map_$t$ *out;
    assert_int_equal(butterflyfish_settable_incremental_map_$t$_as_incremental_map(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_reducible_map_as_settable_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_map_$t$);
    struct butterflyfish_settable_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_settable_map_$t$ *out;
    assert_int_equal(butterflyfish_settable_reducible_map_$t$_as_settable_map(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_reducible_map_as_reducible_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, reducible_map_$t$);
    struct butterflyfish_settable_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_reducible_map_$t$ *out;
    assert_int_equal(butterflyfish_settable_reducible_map_$t$_as_reducible_map(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_mutable_map_as_settable_reducible_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_reducible_map_$t$);
    struct butterflyfish_mutable_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_mutable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_settable_reducible_map_$t$ *out;
    assert_int_equal(butterflyfish_mutable_map_$t$_as_settable_reducible_map(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_mutable_map_as_settable_incremental_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, incremental_map_$t$);
    struct butterflyfish_mutable_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_mutable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_incremental_map_$t$ *out;
    assert_int_equal(butterflyfish_mutable_map_$t$_as_incremental_map(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_settable_reducible_map_as_ordered_settable_map(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_settable_map_$t$);
    struct butterflyfish_ordered_settable_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_settable_map_$t$ *out;
    assert_int_equal(butterflyfish_ordered_settable_reducible_map_$t$_as_ordered_settable_map(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_set_item(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item, 0);
    struct butterflyfish_settable_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    assert_int_equal(butterflyfish_settable_$t$_set_item(
            as, (void *) 1, (void *) 1), 0);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_count(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_count((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_count(
            (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &out),
                    0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_first(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_first((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_map_is_empty(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_first(
                    (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MAP_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_last(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_last((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_map_is_empty(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_last(
                    (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MAP_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_next(
                    (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_prev(
                    (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains(
                    NULL, (void *) 1, (void*) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(set_contains);
    will_return(set_contains,
                BUTTERFLYFISH_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_key_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_key(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_key_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_key(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_contains_key_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_key(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_contains_key);
    will_return(map_contains_key,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_key(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_value_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_value(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_value_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_value(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_contains_value_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_value(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_contains_value_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_contains_value);
    will_return(map_contains_value,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_value(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(set_contains_all);
    will_return(set_contains_all,
                BUTTERFLYFISH_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all_keys(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_keys_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all_keys(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all_keys(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_contains_all_keys);
    will_return(map_contains_all_keys,
                BUTTERFLYFISH_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all_keys(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_values_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all_values(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_values_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all_values(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_values_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all_values(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_values_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_contains_all_values);
    will_return(map_contains_all_values,
                BUTTERFLYFISH_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_contains_all_values(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_entry_not_found(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_$T$_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_value_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_value(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_get_value_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_value(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_get_value_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_value(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_get_value_error_on_value_not_found(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_get_value);
    will_return(map_get_value,
                BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_value(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_NOT_FOUND);
}

static void check_get_value_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_get_value);
    will_return(map_get_value,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_value(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_entry(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_get_entry_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_entry(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_get_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_entry(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_get_entry_error_on_value_not_found(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_get_entry);
    will_return(map_get_entry,
                BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_entry(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_NOT_FOUND);
}

static void check_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_get_entry);
    will_return(map_get_entry,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_get_entry(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_value_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_value(
            NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_set_value_error_on_key_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_value(
            (void *) 1, NULL,(void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL);
}

static void check_set_value_error_on_value_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_value(
            (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_set_value_error_on_key_not_found(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_set_value);
    will_return(settable_map_set_value,
                BUTTERFLYFISH_MAP_$T$_ERROR_KEY_NOT_FOUND);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_value(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND);
}

static void check_set_value_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_set_value);
    will_return(settable_map_set_value,
                BUTTERFLYFISH_SETTABLE_$T$_ERROR_VALUE_IS_INVALID);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_value(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID);
}

static void check_set_value_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_set_value);
    will_return(settable_map_set_value,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_value(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_key_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_key(
            NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_set_key_error_on_key_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_key(
            (void *) 1, NULL,(void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL);
}

static void check_set_key_error_on_value_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_key(
            (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_set_key_error_on_key_not_found(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_set_key);
    will_return(settable_map_set_key,
                BUTTERFLYFISH_MAP_$T$_ERROR_KEY_NOT_FOUND);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_key(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND);
}

static void check_set_key_error_on_key_already_exists(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_set_key);
    will_return(settable_map_set_key,
                BUTTERFLYFISH_SETTABLE_$T$_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_key(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS);
}

static void check_set_key_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_set_key);
    will_return(settable_map_set_key,
                BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_key(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_entry_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_entry(
            NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_set_entry_error_on_key_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_entry(
            (void *) 1, NULL,(void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL);
}

static void check_set_entry_error_on_value_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_entry(
            (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_set_entry_error_on_key_already_exists(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_set_entry);
    will_return(settable_map_set_entry,
                BUTTERFLYFISH_SETTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_entry(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS);
}

static void check_set_entry_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_set_entry);
    will_return(settable_map_set_entry,
                BUTTERFLYFISH_SETTABLE_$T$_ERROR_VALUE_IS_INVALID);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_entry(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID);
}

static void check_set_entry_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_set_entry);
    will_return(settable_map_set_entry,
                BUTTERFLYFISH_SETTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_set_entry(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_add_error_on_entry_is_invalid(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add(
                    (struct butterflyfish_ordered_mutable_map_$t$ *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_INVALID);
}

static void check_add_error_on_key_already_exists(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add(
                    (struct butterflyfish_ordered_mutable_map_$t$ *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add(
                    (struct butterflyfish_ordered_mutable_map_$t$ *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL);
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(addable_add_all);
    will_return(addable_add_all,
                BUTTERFLYFISH_ADDABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add_all(
                    (struct butterflyfish_ordered_mutable_map_$t$ *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_value_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add_value(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_add_value_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add_value(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL);
}

static void check_add_value_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add_value(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_add_value_error_value_is_invalid(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(incremental_map_add_value);
    will_return(incremental_map_add_value,
                BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add_value(
                    (struct butterflyfish_ordered_mutable_map_$t$ *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID);
}

static void check_add_value_error_key_already_exists(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(incremental_map_add_value);
    will_return(incremental_map_add_value,
                BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add_value(
                    (struct butterflyfish_ordered_mutable_map_$t$ *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS);
}

static void check_add_value_error_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(incremental_map_add_value);
    will_return(incremental_map_add_value,
                BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_add_value(
                    (struct butterflyfish_ordered_mutable_map_$t$ *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_insert_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_insert(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_insert_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_insert(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL);
}

static void check_insert_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_insert(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL);
}

static void check_insert_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_insert(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID);
}

static void check_insert_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_insert(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_insert_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_insert_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_insert_all_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_insert_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL);
}

static void check_insert_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_insert_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL);
}

static void check_insert_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(insertable_insert_all);
    will_return(insertable_insert_all,
                BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_insert_all(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove(
            NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_key_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove(
            (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL);
}

static void check_remove_error_on_key_not_found(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(reducible_map_remove);
    will_return(reducible_map_remove,
                BUTTERFLYFISH_REDUCIBLE_MAP_$T$_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_remove(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(reducible_map_remove);
    will_return(reducible_map_remove,
                BUTTERFLYFISH_REDUCIBLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_remove(
                    (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove_all(
            NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_other_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove_all(
            (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(reducible_map_remove_all);
    will_return(reducible_map_remove_all,
                BUTTERFLYFISH_REDUCIBLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_remove_all(
                    (struct butterflyfish_ordered_mutable_map_$t$ *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_retain_all(
            NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_other_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_retain_all(
            (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL);
}

static void check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(reducible_map_retain_all);
    will_return(reducible_map_retain_all,
                BUTTERFLYFISH_REDUCIBLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_retain_all(
                    (struct butterflyfish_ordered_mutable_map_$t$ *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_entry_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove_entry(
            NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_remove_entry_error_on_entry_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove_entry(
            (void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL);
}

static void check_remove_entry(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(removable_remove_item);
    will_return(removable_remove_item, 0);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove_entry(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
            (void *) 1), 0);
}

static void check_remove_all_entries_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove_all_entries(
            NULL, (void*) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_entries_error_on_entries_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove_all_entries(
            (void *) 1,NULL),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_entries(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(removable_remove_all_items);
    will_return(removable_remove_all_items, 0);
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_remove_all_entries(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
            (void *) 1), 0);
}

static void check_keys_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_keys(NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_keys_error_on_out_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_keys((void *) 1,NULL),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_mutable_map_keys);
    will_return(ordered_mutable_map_keys, 0);
    struct butterflyfish_ordered_mutable_set_$mkt$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_keys(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &out), 0);
}

static void check_as_ordered_settable_incremental_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_settable_incremental_map_keys);
    will_return(ordered_settable_incremental_map_keys, 0);
    struct butterflyfish_ordered_settable_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_ordered_settable_incremental_set_$mkt$ *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_map_$t$_keys(as, &out), 0);
}

static void check_as_ordered_settable_reducible_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_settable_reducible_map_keys);
    will_return(ordered_settable_reducible_map_keys, 0);
    struct butterflyfish_ordered_settable_reducible_map_$t$ *as;
    assert_int_equal(
            butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_ordered_settable_reducible_set_$mkt$ *out;
    assert_int_equal(butterflyfish_ordered_settable_reducible_map_$t$_keys(
            as, &out), 0);
}

static void check_as_ordered_settable_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_settable_map_keys);
    will_return(ordered_settable_map_keys, 0);
    struct butterflyfish_ordered_settable_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_ordered_settable_set_$mkt$ *out;
    assert_int_equal(butterflyfish_ordered_settable_map_$t$_keys(as, &out), 0);
}

static void check_as_settable_incremental_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_incremental_map_keys);
    will_return(settable_incremental_map_keys, 0);
    struct butterflyfish_settable_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_settable_incremental_set_$mkt$ *out;
    assert_int_equal(butterflyfish_settable_incremental_map_$t$_keys(as, &out),
                     0);
}

static void check_as_settable_reducible_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_reducible_map_keys);
    will_return(settable_reducible_map_keys, 0);
    struct butterflyfish_settable_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_settable_reducible_set_$mkt$ *out;
    assert_int_equal(butterflyfish_settable_reducible_map_$t$_keys(as, &out),
                     0);
}

static void check_as_ordered_incremental_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_incremental_map_keys);
    will_return(ordered_incremental_map_keys, 0);
    struct butterflyfish_ordered_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_ordered_incremental_set_$mkt$ *out;
    assert_int_equal(butterflyfish_ordered_incremental_map_$t$_keys(as, &out),
                     0);
}

static void check_as_ordered_reducible_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_reducible_map_keys);
    will_return(ordered_reducible_map_keys, 0);
    struct butterflyfish_ordered_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_ordered_reducible_set_$mkt$ *out;
    assert_int_equal(butterflyfish_ordered_reducible_map_$t$_keys(as, &out),
                     0);
}

static void check_as_incremental_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(incremental_map_keys);
    will_return(incremental_map_keys, 0);
    struct butterflyfish_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_incremental_set_$mkt$ *out;
    assert_int_equal(butterflyfish_incremental_map_$t$_keys(as, &out), 0);
}

static void check_as_reducible_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(reducible_map_keys);
    will_return(reducible_map_keys, 0);
    struct butterflyfish_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_reducible_set_$mkt$ *out;
    assert_int_equal(butterflyfish_reducible_map_$t$_keys(as, &out), 0);
}

static void check_as_ordered_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_map_keys);
    will_return(ordered_map_keys, 0);
    const struct butterflyfish_ordered_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_map(
            (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_ordered_set_$mkt$ *out;
    assert_int_equal(butterflyfish_ordered_map_$t$_keys(as, &out), 0);
}

static void check_as_settable_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_keys);
    will_return(settable_map_keys, 0);
    struct butterflyfish_settable_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *)
                    &instance, &as), 0);
    struct butterflyfish_settable_set_$mkt$ *out;
    assert_int_equal(butterflyfish_settable_map_$t$_keys(as, &out), 0);
}

static void check_as_mutable_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(mutable_map_keys);
    will_return(mutable_map_keys, 0);
    struct butterflyfish_mutable_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_mutable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_mutable_set_$mkt$ *out;
    assert_int_equal(butterflyfish_mutable_map_$t$_keys(as, &out), 0);
}

static void check_as_map_keys(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_keys);
    will_return(map_keys, 0);
    const struct butterflyfish_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_map(
            (const struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_set_$mkt$ *out;
    assert_int_equal(butterflyfish_map_$t$_keys(as, &out), 0);
}

static void check_values_error_on_object_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_values(NULL, (void *) 1),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_values_error_on_out_is_null(void **state) {
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_values((void *) 1, NULL),
                     BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL);
}

static void check_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_mutable_map_values);
    will_return(ordered_mutable_map_values, 0);
    struct butterflyfish_ordered_settable_reducible_list_$mvt$ *out;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_values(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &out), 0);
}

static void check_as_ordered_settable_incremental_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_settable_incremental_map_values);
    will_return(ordered_settable_incremental_map_values, 0);
    struct butterflyfish_ordered_settable_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_settable_list_$mvt$ *out;
    assert_int_equal(butterflyfish_ordered_settable_incremental_map_$t$_values(as, &out),
                     0);
}

static void check_as_ordered_settable_reducible_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_settable_reducible_map_values);
    will_return(ordered_settable_reducible_map_values, 0);
    struct butterflyfish_ordered_settable_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_settable_reducible_list_$mvt$ *out;
    assert_int_equal(butterflyfish_ordered_settable_reducible_map_$t$_values(as, &out),
                     0);
}

static void check_as_ordered_settable_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_settable_map_values);
    will_return(ordered_settable_map_values, 0);
    struct butterflyfish_ordered_settable_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_settable_list_$mvt$ *out;
    assert_int_equal(butterflyfish_ordered_settable_map_$t$_values(as, &out),
                     0);
}

static void check_as_settable_incremental_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_incremental_map_values);
    will_return(settable_incremental_map_values, 0);
    struct butterflyfish_settable_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_settable_list_$mvt$ *out;
    assert_int_equal(butterflyfish_settable_incremental_map_$t$_values(as, &out),
                     0);
}

static void check_as_settable_reducible_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_reducible_map_values);
    will_return(settable_reducible_map_values, 0);
    struct butterflyfish_settable_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_settable_reducible_list_$mvt$ *out;
    assert_int_equal(butterflyfish_settable_reducible_map_$t$_values(as, &out),
                     0);
}

static void check_as_ordered_incremental_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_incremental_map_values);
    will_return(ordered_incremental_map_values, 0);
    struct butterflyfish_ordered_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_ordered_list_$mvt$ *out;
    assert_int_equal(butterflyfish_ordered_incremental_map_$t$_values(as, &out),
                     0);
}

static void check_as_ordered_reducible_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_reducible_map_values);
    will_return(ordered_reducible_map_values, 0);
    struct butterflyfish_ordered_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_reducible_list_$mvt$ *out;
    assert_int_equal(butterflyfish_ordered_reducible_map_$t$_values(as, &out),
                     0);
}

static void check_as_incremental_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(incremental_map_values);
    will_return(incremental_map_values, 0);
    struct butterflyfish_incremental_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_incremental_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    const struct butterflyfish_ordered_list_$mvt$ *out;
    assert_int_equal(butterflyfish_incremental_map_$t$_values(as, &out),
                     0);
}

static void check_as_reducible_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(reducible_map_values);
    will_return(reducible_map_values, 0);
    struct butterflyfish_reducible_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_reducible_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_reducible_list_$mvt$ *out;
    assert_int_equal(butterflyfish_reducible_map_$t$_values(as, &out),
                     0);
}

static void check_as_settable_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(settable_map_values);
    will_return(settable_map_values, 0);
    struct butterflyfish_settable_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_settable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_settable_list_$mvt$ *out;
    assert_int_equal(butterflyfish_settable_map_$t$_values(as, &out), 0);
}

static void check_as_ordered_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(ordered_map_values);
    will_return(ordered_map_values, 0);
    const struct butterflyfish_ordered_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_ordered_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &as),
                    0);
    const struct butterflyfish_ordered_list_$mvt$ *out;
    assert_int_equal(butterflyfish_ordered_map_$t$_values(as, &out), 0);
}

static void check_as_mutable_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(mutable_map_values);
    will_return(mutable_map_values, 0);
    struct butterflyfish_mutable_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_mutable_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &as),
                    0);
    struct butterflyfish_ordered_settable_reducible_list_$mvt$ *out;
    assert_int_equal(butterflyfish_mutable_map_$t$_values(as, &out), 0);
}

static void check_as_map_values(void **state) {
    const struct object instance = {
            .ordered_mutable_map_$t$ = &ordered_mutable_map_$t$,
            .ordered_settable_incremental_map_$t$ =
                    &ordered_settable_incremental_map_$t$,
            .ordered_settable_reducible_map_$t$ =
                    &ordered_settable_reducible_map_$t$,
            .mutable_map_$t$ = &mutable_map_$t$,
            .settable_incremental_map_$t$ = &settable_incremental_map_$t$,
            .settable_reducible_map_$t$ = &settable_reducible_map_$t$,
            .ordered_settable_map_$t$ = &ordered_settable_map_$t$,
            .ordered_incremental_map_$t$ = &ordered_incremental_map_$t$,
            .ordered_reducible_map_$t$ = &ordered_reducible_map_$t$,
            .ordered_map_$t$ = &ordered_map_$t$,
            .settable_map_$t$ = &settable_map_$t$,
            .incremental_map_$t$ = &incremental_map_$t$,
            .reducible_map_$t$ = &reducible_map_$t$,
            .map_$t$ = &map_$t$,
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .addable_$t$ = &addable_$t$,
            .removable_$t$ = &removable_$t$,
            .settable_$t$ = &settable_$t$,
            .set_$t$ = &set_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(map_values);
    will_return(map_values, 0);
    const struct butterflyfish_map_$t$ *as;
    assert_int_equal(butterflyfish_ordered_mutable_map_$t$_as_map(
            (struct butterflyfish_ordered_mutable_map_$t$ *) &instance, &as),
                    0);
    const struct butterflyfish_ordered_list_$mvt$ *out;
    assert_int_equal(butterflyfish_map_$t$_values(as, &out), 0);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_set_error_on_object_is_null),
            cmocka_unit_test(check_as_set_error_on_out_is_null),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_as_settable_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_error_on_out_is_null),
            cmocka_unit_test(check_as_settable),
            cmocka_unit_test(check_as_removable_error_on_object_is_null),
            cmocka_unit_test(check_as_removable_error_on_out_is_null),
            cmocka_unit_test(check_as_removable),
            cmocka_unit_test(check_as_addable_error_on_object_is_null),
            cmocka_unit_test(check_as_addable_error_on_out_is_null),
            cmocka_unit_test(check_as_addable),
            cmocka_unit_test(check_as_map_error_on_object_is_null),
            cmocka_unit_test(check_as_map_error_on_out_is_null),
            cmocka_unit_test(check_as_map),
            cmocka_unit_test(check_as_ordered_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered),
            cmocka_unit_test(check_as_insertable_error_on_object_is_null),
            cmocka_unit_test(check_as_insertable_error_on_out_is_null),
            cmocka_unit_test(check_as_insertable),
            cmocka_unit_test(check_as_reducible_map_error_on_object_is_null),
            cmocka_unit_test(check_as_reducible_map_error_on_out_is_null),
            cmocka_unit_test(check_as_reducible_map),
            cmocka_unit_test(check_as_incremental_map_error_on_object_is_null),
            cmocka_unit_test(check_as_incremental_map_error_on_out_is_null),
            cmocka_unit_test(check_as_incremental_map),
            cmocka_unit_test(check_as_settable_map_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_map_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_map),
            cmocka_unit_test(check_as_ordered_map_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_map_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_map),
            cmocka_unit_test(check_as_ordered_reducible_map_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_reducible_map_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_reducible_map),
            cmocka_unit_test(check_as_ordered_incremental_map_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_incremental_map_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_incremental_map),
            cmocka_unit_test(check_as_ordered_settable_map_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_settable_map_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_settable_map),
            cmocka_unit_test(check_as_settable_reducible_map_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_reducible_map_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_reducible_map),
            cmocka_unit_test(check_as_settable_incremental_map_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_incremental_map_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_incremental_map),
            cmocka_unit_test(check_as_mutable_map_error_on_object_is_null),
            cmocka_unit_test(check_as_mutable_map_error_on_out_is_null),
            cmocka_unit_test(check_as_mutable_map),
            cmocka_unit_test(check_as_ordered_settable_reducible_map_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_settable_reducible_map_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_settable_reducible_map),
            cmocka_unit_test(check_as_ordered_settable_incremental_map_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_settable_incremental_map_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_settable_incremental_map),
            cmocka_unit_test(check_addable_as_collection),
            cmocka_unit_test(check_ordered_as_collection),
            cmocka_unit_test(check_removable_as_collection),
            cmocka_unit_test(check_settable_as_collection),
            cmocka_unit_test(check_insertable_as_collection),
            cmocka_unit_test(check_ordered_map_as_ordered),
            cmocka_unit_test(check_incremental_map_as_map),
            cmocka_unit_test(check_reducible_map_as_map),
            cmocka_unit_test(check_settable_map_as_map),
            cmocka_unit_test(check_ordered_incremental_map_as_ordered_map),
            cmocka_unit_test(check_ordered_reducible_map_as_ordered_map),
            cmocka_unit_test(check_settable_incremental_map_as_settable_map),
            cmocka_unit_test(check_settable_incremental_map_as_incremental_map),
            cmocka_unit_test(check_settable_reducible_map_as_settable_map),
            cmocka_unit_test(check_settable_reducible_map_as_reducible_map),
            cmocka_unit_test(check_mutable_map_as_settable_reducible_map),
            cmocka_unit_test(check_mutable_map_as_settable_incremental_map),
            cmocka_unit_test(check_ordered_settable_reducible_map_as_ordered_settable_map),
            cmocka_unit_test(check_as_settable_set_item),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_map_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_map_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_contains_error_on_object_is_null),
            cmocka_unit_test(check_contains_error_on_entry_is_null),
            cmocka_unit_test(check_contains_error_on_out_is_null),
            cmocka_unit_test(check_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_key_error_on_object_is_null),
            cmocka_unit_test(check_contains_key_error_on_value_is_null),
            cmocka_unit_test(check_contains_key_error_on_out_is_null),
            cmocka_unit_test(check_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_value_error_on_object_is_null),
            cmocka_unit_test(check_contains_value_error_on_value_is_null),
            cmocka_unit_test(check_contains_value_error_on_out_is_null),
            cmocka_unit_test(check_contains_value_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_keys_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_values_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_values_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_values_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_values_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_entry_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_entry_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_value_error_on_object_is_null),
            cmocka_unit_test(check_get_value_error_on_value_is_null),
            cmocka_unit_test(check_get_value_error_on_out_is_null),
            cmocka_unit_test(check_get_value_error_on_value_not_found),
            cmocka_unit_test(check_get_value_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_entry_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_value_is_null),
            cmocka_unit_test(check_get_entry_error_on_out_is_null),
            cmocka_unit_test(check_get_entry_error_on_value_not_found),
            cmocka_unit_test(check_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_value_error_on_object_is_null),
            cmocka_unit_test(check_set_value_error_on_key_is_null),
            cmocka_unit_test(check_set_value_error_on_value_is_null),
            cmocka_unit_test(check_set_value_error_on_key_not_found),
            cmocka_unit_test(check_set_value_error_on_value_is_invalid),
            cmocka_unit_test(check_set_value_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_key_error_on_object_is_null),
            cmocka_unit_test(check_set_key_error_on_key_is_null),
            cmocka_unit_test(check_set_key_error_on_value_is_null),
            cmocka_unit_test(check_set_key_error_on_object_is_null),
            cmocka_unit_test(check_set_key_error_on_key_is_null),
            cmocka_unit_test(check_set_key_error_on_value_is_null),
            cmocka_unit_test(check_set_key_error_on_key_not_found),
            cmocka_unit_test(check_set_key_error_on_key_already_exists),
            cmocka_unit_test(check_set_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_entry_error_on_object_is_null),
            cmocka_unit_test(check_set_entry_error_on_key_is_null),
            cmocka_unit_test(check_set_entry_error_on_value_is_null),
            cmocka_unit_test(check_set_entry_error_on_key_already_exists),
            cmocka_unit_test(check_set_entry_error_on_value_is_invalid),
            cmocka_unit_test(check_set_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_entry_is_invalid),
            cmocka_unit_test(check_add_error_on_key_already_exists),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_value_error_on_object_is_null),
            cmocka_unit_test(check_add_value_error_on_key_is_null),
            cmocka_unit_test(check_add_value_error_on_value_is_null),
            cmocka_unit_test(check_add_value_error_value_is_invalid),
            cmocka_unit_test(check_add_value_error_key_already_exists),
            cmocka_unit_test(check_add_value_error_memory_allocation_failed),
            cmocka_unit_test(check_insert_error_on_object_is_null),
            cmocka_unit_test(check_insert_error_on_item_is_null),
            cmocka_unit_test(check_insert_error_on_value_is_null),
            cmocka_unit_test(check_insert_error_on_value_is_invalid),
            cmocka_unit_test(check_insert_error_on_memory_allocation_failed),
            cmocka_unit_test(check_insert_all_error_on_object_is_null),
            cmocka_unit_test(check_insert_all_error_on_item_is_null),
            cmocka_unit_test(check_insert_all_error_on_other_is_null),
            cmocka_unit_test(check_insert_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_key_is_null),
            cmocka_unit_test(check_remove_error_on_key_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_other_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_retain_all_error_on_object_is_null),
            cmocka_unit_test(check_retain_all_error_on_other_is_null),
            cmocka_unit_test(check_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_entry_error_on_object_is_null),
            cmocka_unit_test(check_remove_entry_error_on_entry_is_null),
            cmocka_unit_test(check_remove_entry),
            cmocka_unit_test(check_remove_all_entries_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_entries_error_on_entries_is_null),
            cmocka_unit_test(check_remove_all_entries),
            cmocka_unit_test(check_keys_error_on_object_is_null),
            cmocka_unit_test(check_keys_error_on_out_is_null),
            cmocka_unit_test(check_keys),
            cmocka_unit_test(check_as_ordered_settable_incremental_map_keys),
            cmocka_unit_test(check_as_ordered_settable_reducible_map_keys),
            cmocka_unit_test(check_as_ordered_settable_map_keys),
            cmocka_unit_test(check_as_settable_incremental_map_keys),
            cmocka_unit_test(check_as_settable_reducible_map_keys),
            cmocka_unit_test(check_as_ordered_incremental_map_keys),
            cmocka_unit_test(check_as_ordered_reducible_map_keys),
            cmocka_unit_test(check_as_incremental_map_keys),
            cmocka_unit_test(check_as_reducible_map_keys),
            cmocka_unit_test(check_as_ordered_map_keys),
            cmocka_unit_test(check_as_settable_map_keys),
            cmocka_unit_test(check_as_mutable_map_keys),
            cmocka_unit_test(check_as_map_keys),
            cmocka_unit_test(check_values_error_on_object_is_null),
            cmocka_unit_test(check_values_error_on_out_is_null),
            cmocka_unit_test(check_values),
            cmocka_unit_test(check_as_ordered_settable_incremental_map_values),
            cmocka_unit_test(check_as_ordered_settable_reducible_map_values),
            cmocka_unit_test(check_as_ordered_settable_map_values),
            cmocka_unit_test(check_as_settable_incremental_map_values),
            cmocka_unit_test(check_as_settable_reducible_map_values),
            cmocka_unit_test(check_as_ordered_incremental_map_values),
            cmocka_unit_test(check_as_ordered_reducible_map_values),
            cmocka_unit_test(check_as_incremental_map_values),
            cmocka_unit_test(check_as_reducible_map_values),
            cmocka_unit_test(check_as_ordered_map_values),
            cmocka_unit_test(check_as_settable_map_values),
            cmocka_unit_test(check_as_mutable_map_values),
            cmocka_unit_test(check_as_map_values),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}

