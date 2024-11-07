#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

struct object {
    const struct butterflyfish_swappable_mutable_set_i *const
            swappable_mutable_set_i;
    const struct butterflyfish_swappable_settable_incremental_set_i *const
            swappable_settable_incremental_set_i;
    const struct butterflyfish_swappable_settable_reducible_set_i *const
            swappable_settable_reducible_set_i;
    const struct butterflyfish_swappable_reducible_set_i *const
            swappable_reducible_set_i;
    const struct butterflyfish_swappable_incremental_set_i *const
            swappable_incremental_set_i;
    const struct butterflyfish_swappable_settable_set_i *const
            swappable_settable_set_i;
    const struct butterflyfish_ordered_mutable_set_i *const
            ordered_mutable_set_i;
    const struct butterflyfish_ordered_settable_incremental_set_i *const
            ordered_settable_incremental_set_i;
    const struct butterflyfish_ordered_settable_reducible_set_i *const
            ordered_settable_reducible_set_i;
    const struct butterflyfish_ordered_reducible_set_i *const
            ordered_reducible_set_i;
    const struct butterflyfish_ordered_incremental_set_i *const
            ordered_incremental_set_i;
    const struct butterflyfish_ordered_settable_set_i *const
            ordered_settable_set_i;
    const struct butterflyfish_ordered_set_i *const ordered_set_i;
    const struct butterflyfish_mutable_set_i *const mutable_set_i;
    const struct butterflyfish_settable_incremental_set_i *const
            settable_incremental_set_i;
    const struct butterflyfish_settable_reducible_set_i *const
            settable_reducible_set_i;
    const struct butterflyfish_reducible_set_i *const reducible_set_i;
    const struct butterflyfish_incremental_set_i *const incremental_set_i;
    const struct butterflyfish_settable_set_i *const settable_set_i;
    const struct butterflyfish_swappable_set_i *const swappable_set_i;
    const struct butterflyfish_set_i *const set_i;
    const struct butterflyfish_swappable_i *const swappable_i;
    const struct butterflyfish_insertable_i *const insertable_i;
    const struct butterflyfish_ordered_i *const ordered_i;
    const struct butterflyfish_settable_i *const settable_i;
    const struct butterflyfish_removable_i *const removable_i;
    const struct butterflyfish_addable_i *const addable_i;
    const struct butterflyfish_collection_i *const collection_i;
    const struct butterflyfish_stream_i *const stream_i;
};

static int stream_first(const struct butterflyfish_stream_i *const object,
                        const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int stream_next(const struct butterflyfish_stream_i *const object,
                       const struct sea_turtle_integer *const item,
                       const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_stream_i stream_i = {
        .first = stream_first,
        .next = stream_next
};

static int as_stream(const struct butterflyfish_collection_i *const object,
                     const struct butterflyfish_stream_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, collection_i, stream_i);
    return 0;
}

static int
collection_last(const struct butterflyfish_collection_i *const object,
                const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
collection_prev(const struct butterflyfish_collection_i *const object,
                const struct sea_turtle_integer *const item,
                const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static int
collection_count(const struct butterflyfish_collection_i *const object,
                 uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_i collection_i = {
        .as_stream = as_stream,
        .last = collection_last,
        .prev = collection_prev,
        .count = collection_count,
};

static int
ordered_as_collection(const struct butterflyfish_ordered_i *const object,
                      const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_i, collection_i);
    return 0;
}

const struct butterflyfish_ordered_i ordered_i = {
        .as_collection = ordered_as_collection,
};

static int
swappable_as_ordered(const struct butterflyfish_swappable_i *const object,
                     const struct butterflyfish_ordered_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, swappable_i, ordered_i);
    return 0;
}

static int
swappable_swap(struct butterflyfish_swappable_i *const object,
               const struct sea_turtle_integer *const item,
               const struct sea_turtle_integer *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_swappable_i swappable_i = {
        .as_ordered = swappable_as_ordered,
        .swap = swappable_swap
};

static int
swappable_set_as_ordered_set(
        const struct butterflyfish_swappable_set_i *const object,
        const struct butterflyfish_ordered_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, swappable_set_i,
                              ordered_set_i);
    return 0;
}

static int
swappable_set_as_swappable(
        struct butterflyfish_swappable_set_i *const object,
        struct butterflyfish_swappable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, swappable_set_i,
                              swappable_i);
    return 0;
}

const struct butterflyfish_swappable_set_i swappable_set_i = {
        .as_ordered_set = swappable_set_as_ordered_set,
        .as_swappable = swappable_set_as_swappable,
};

static int
set_as_collection(const struct butterflyfish_set_i *const object,
                  const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, set_i, collection_i);
    return 0;
}

static int set_contains(const struct butterflyfish_set_i *const object,
                        const struct sea_turtle_integer *const value,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static int set_contains_all(const struct butterflyfish_set_i *const object,
                            const struct butterflyfish_stream_i *const other,
                            bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static int set_get(const struct butterflyfish_set_i *const object,
                   const struct sea_turtle_integer *const value,
                   const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_set_i set_i = {
        .as_collection = set_as_collection,
        .contains = set_contains,
        .contains_all = set_contains_all,
        .get = set_get
};

static int
settable_as_collection(const struct butterflyfish_settable_i *const object,
                       const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_i, collection_i);
    return 0;
}

static int
settable_set_item(struct butterflyfish_settable_i *const object,
                  const struct sea_turtle_integer *const item,
                  const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_i settable_i = {
        .as_collection = settable_as_collection,
        .set_item = settable_set_item,
};

static int
addable_as_collection(const struct butterflyfish_addable_i *const object,
                      const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, addable_i, collection_i);
    return 0;
}

static int
addable_add(struct butterflyfish_addable_i *const object,
            const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static int
addable_add_all(struct butterflyfish_addable_i *const object,
                const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_addable_i addable_i = {
        .as_collection = addable_as_collection,
        .add = addable_add,
        .add_all = addable_add_all,
};

static int
settable_set_as_set(const struct butterflyfish_settable_set_i *const object,
                    const struct butterflyfish_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_set_i, set_i);
    return 0;
}

static int
settable_set_as_settable(struct butterflyfish_settable_set_i *const object,
                         struct butterflyfish_settable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_set_i, settable_i);
    return 0;
}

static int settable_set_set(struct butterflyfish_settable_set_i *const object,
                         const struct sea_turtle_integer *const item,
                         const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

const struct butterflyfish_settable_set_i settable_set_i = {
        .as_settable = settable_set_as_settable,
        .as_set = settable_set_as_set,
        .set = settable_set_set,
};

static int
ordered_set_as_ordered(const struct butterflyfish_ordered_set_i *const object,
                       const struct butterflyfish_ordered_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_set_i, ordered_i);
    return 0;
}

static int
ordered_set_as_set(const struct butterflyfish_ordered_set_i *const object,
                   const struct butterflyfish_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_set_i, set_i);
    return 0;
}

const struct butterflyfish_ordered_set_i ordered_set_i = {
        .as_ordered = ordered_set_as_ordered,
        .as_set = ordered_set_as_set,
};

static int
ordered_settable_set_as_ordered_set(
        const struct butterflyfish_ordered_settable_set_i *const object,
        const struct butterflyfish_ordered_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_settable_set_i,
                              ordered_set_i);
    return 0;
}

static int
ordered_settable_set_as_settable_set(
        struct butterflyfish_ordered_settable_set_i *const object,
        struct butterflyfish_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_settable_set_i,
                              settable_set_i);
    return 0;
}

const struct butterflyfish_ordered_settable_set_i ordered_settable_set_i = {
        .as_settable_set = ordered_settable_set_as_settable_set,
        .as_ordered_set = ordered_settable_set_as_ordered_set,
};

static int
incremental_set_as_set(
        const struct butterflyfish_incremental_set_i *const object,
        const struct butterflyfish_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_set_i, set_i);
    return 0;
}

static int
incremental_set_as_addable(struct butterflyfish_incremental_set_i *const object,
                           struct butterflyfish_addable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_set_i,
            addable_i);
    return 0;
}

const struct butterflyfish_incremental_set_i incremental_set_i = {
        .as_addable = incremental_set_as_addable,
        .as_set = incremental_set_as_set,
};

static int
insertable_as_ordered(const struct butterflyfish_insertable_i *const object,
                      const struct butterflyfish_ordered_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, insertable_i, ordered_i);
    return 0;
}

static int
insertable_insert(struct butterflyfish_insertable_i *const object,
                  const struct sea_turtle_integer *const item,
                  const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

static int insertable_insert_all(
        struct butterflyfish_insertable_i *const object,
        const struct sea_turtle_integer *const item,
        const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_insertable_i insertable_i = {
        .as_ordered = insertable_as_ordered,
        .insert = insertable_insert,
        .insert_all = insertable_insert_all,
};

static int
ordered_incremental_set_as_ordered_set(
        const struct butterflyfish_ordered_incremental_set_i *const object,
        const struct butterflyfish_ordered_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_incremental_set_i,
                              ordered_set_i);
    return 0;
}

static int
ordered_incremental_set_as_insertable(
        struct butterflyfish_ordered_incremental_set_i *const object,
        struct butterflyfish_insertable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_incremental_set_i,
                              insertable_i);
    return 0;
}

static int
ordered_incremental_set_as_incremental_set(
        struct butterflyfish_ordered_incremental_set_i *const object,
        struct butterflyfish_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_incremental_set_i,
                              incremental_set_i);
    return 0;
}

const struct
butterflyfish_ordered_incremental_set_i ordered_incremental_set_i = {
        .as_insertable = ordered_incremental_set_as_insertable,
        .as_ordered_set = ordered_incremental_set_as_ordered_set,
        .as_incremental_set = ordered_incremental_set_as_incremental_set,
};

static int
removable_as_collection(const struct butterflyfish_removable_i *const object,
                        const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, removable_i,
            collection_i);
    return 0;
}

static int
removable_remove_item(struct butterflyfish_removable_i *const object,
                      const struct sea_turtle_integer *item) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return mock();
}

static int
removable_remove_all_items(struct butterflyfish_removable_i *const object,
                           const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_removable_i removable_i = {
        .as_collection = removable_as_collection,
        .remove_item = removable_remove_item,
        .remove_all_items = removable_remove_all_items,
};

static int
reducible_set_as_removable(struct butterflyfish_reducible_set_i *const object,
                           struct butterflyfish_removable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_set_i,
            removable_i);
    return 0;
}

static int
reducible_set_as_set(
        const struct butterflyfish_reducible_set_i *const object,
        const struct butterflyfish_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, reducible_set_i, set_i);
    return 0;
}

static int
reducible_set_remove(struct butterflyfish_reducible_set_i *const object,
                     const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static int
reducible_set_remove_all(struct butterflyfish_reducible_set_i *const object,
                         const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static int
reducible_set_retain_all(struct butterflyfish_reducible_set_i *const object,
                         const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_reducible_set_i reducible_set_i = {
        .as_removable = reducible_set_as_removable,
        .as_set = reducible_set_as_set,
        .remove = reducible_set_remove,
        .remove_all = reducible_set_remove_all,
        .retain_all = reducible_set_retain_all,
};

static int
ordered_reducible_set_as_ordered_set(
        const struct butterflyfish_ordered_reducible_set_i *const object,
        const struct butterflyfish_ordered_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_reducible_set_i,
                              ordered_set_i);
    return 0;
}

static int
ordered_reducible_set_as_reducible_set(
        struct butterflyfish_ordered_reducible_set_i *const object,
        struct butterflyfish_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_reducible_set_i,
                              reducible_set_i);
    return 0;
}

const struct
butterflyfish_ordered_reducible_set_i ordered_reducible_set_i = {
    .as_ordered_set = ordered_reducible_set_as_ordered_set,
    .as_reducible_set = ordered_reducible_set_as_reducible_set,
};

static int
settable_reducible_set_as_settable_set(
        struct butterflyfish_settable_reducible_set_i *const object,
        struct butterflyfish_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_reducible_set_i,
                              settable_set_i);
    return 0;
}

static int
settable_reducible_set_as_reducible_set(
        struct butterflyfish_settable_reducible_set_i *const object,
        struct butterflyfish_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, settable_reducible_set_i,
                              reducible_set_i);
    return 0;
}

const struct
butterflyfish_settable_reducible_set_i settable_reducible_set_i = {
        .as_settable_set = settable_reducible_set_as_settable_set,
        .as_reducible_set = settable_reducible_set_as_reducible_set,
};

static int
settable_incremental_set_as_incremental_set(
        struct butterflyfish_settable_incremental_set_i *const object,
        struct butterflyfish_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              settable_incremental_set_i, incremental_set_i);
    return 0;
}

static int
settable_incremental_set_as_settable_set(
        struct butterflyfish_settable_incremental_set_i *const object,
        struct butterflyfish_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              settable_incremental_set_i, settable_set_i);
    return 0;
}

const struct
butterflyfish_settable_incremental_set_i settable_incremental_set_i = {
        .as_incremental_set = settable_incremental_set_as_incremental_set,
        .as_settable_set = settable_incremental_set_as_settable_set,
};

static int
mutable_set_as_settable_incremental_set(
        struct butterflyfish_mutable_set_i *const object,
        struct butterflyfish_settable_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, mutable_set_i,
                              settable_incremental_set_i);
    return 0;
}

static int
mutable_set_as_settable_reducible_set(
        struct butterflyfish_mutable_set_i *const object,
        struct butterflyfish_settable_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, mutable_set_i,
                              settable_reducible_set_i);
    return 0;
}

const struct butterflyfish_mutable_set_i mutable_set_i = {
        .as_settable_incremental_set = mutable_set_as_settable_incremental_set,
        .as_settable_reducible_set = mutable_set_as_settable_reducible_set
};

static int
ordered_settable_incremental_set_as_settable_incremental_set(
        struct butterflyfish_ordered_settable_incremental_set_i *const object,
        struct butterflyfish_settable_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_settable_incremental_set_i,
                              settable_incremental_set_i);
    return 0;
}

static int
ordered_settable_incremental_set_as_ordered_incremental_set(
        struct butterflyfish_ordered_settable_incremental_set_i *const object,
        struct butterflyfish_ordered_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_settable_incremental_set_i,
                              ordered_incremental_set_i);
    return 0;
}

static int
ordered_settable_incremental_set_as_ordered_settable_set(
        struct butterflyfish_ordered_settable_incremental_set_i *const object,
        struct butterflyfish_ordered_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_settable_incremental_set_i,
                              ordered_settable_set_i);
    return 0;
}

const struct butterflyfish_ordered_settable_incremental_set_i
ordered_settable_incremental_set_i = {
        .as_settable_incremental_set =
                ordered_settable_incremental_set_as_settable_incremental_set,
        .as_ordered_incremental_set =
                ordered_settable_incremental_set_as_ordered_incremental_set,
        .as_ordered_settable_set =
                ordered_settable_incremental_set_as_ordered_settable_set,
};

static int
ordered_settable_reducible_set_as_settable_reducible_set(
        struct butterflyfish_ordered_settable_reducible_set_i *const object,
        struct butterflyfish_settable_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_settable_reducible_set_i,
                              settable_reducible_set_i);
    return 0;
}

static int
ordered_settable_reducible_set_as_ordered_settable_set(
        struct butterflyfish_ordered_settable_reducible_set_i *const object,
        struct butterflyfish_ordered_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_settable_reducible_set_i,
                              ordered_settable_set_i);
    return 0;
}

static int
ordered_settable_reducible_set_as_ordered_reducible_set(
        struct butterflyfish_ordered_settable_reducible_set_i *const object,
        struct butterflyfish_ordered_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              ordered_settable_reducible_set_i,
                              ordered_reducible_set_i);
    return 0;
}

const struct butterflyfish_ordered_settable_reducible_set_i
ordered_settable_reducible_set_i = {
        .as_settable_reducible_set =
                ordered_settable_reducible_set_as_settable_reducible_set,
        .as_ordered_settable_set =
                ordered_settable_reducible_set_as_ordered_settable_set,
        .as_ordered_reducible_set =
                ordered_settable_reducible_set_as_ordered_reducible_set,
};

static int
ordered_mutable_set_as_ordered_settable_incremental_set(
        struct butterflyfish_ordered_mutable_set_i *const object,
        struct butterflyfish_ordered_settable_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_mutable_set_i,
                              ordered_settable_incremental_set_i);
    return 0;
}

static int
ordered_mutable_set_as_ordered_settable_reducible_set(
        struct butterflyfish_ordered_mutable_set_i *const object,
        struct butterflyfish_ordered_settable_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_mutable_set_i,
                              ordered_settable_reducible_set_i);
    return 0;
}

static int
ordered_mutable_set_as_mutable_set(
        struct butterflyfish_ordered_mutable_set_i *const object,
        struct butterflyfish_mutable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_mutable_set_i,
                              mutable_set_i);
    return 0;
}

const struct butterflyfish_ordered_mutable_set_i ordered_mutable_set_i = {
        .as_ordered_settable_incremental_set =
                ordered_mutable_set_as_ordered_settable_incremental_set,
        .as_ordered_settable_reducible_set =
                ordered_mutable_set_as_ordered_settable_reducible_set,
        .as_mutable_set = ordered_mutable_set_as_mutable_set,
};

static int
swappable_settable_set_as_swappable_set(
        struct butterflyfish_swappable_settable_set_i *const object,
        struct butterflyfish_swappable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, swappable_settable_set_i,
                              swappable_set_i);
    return 0;
}

static int
swappable_settable_set_as_ordered_settable_set(
        struct butterflyfish_swappable_settable_set_i *const object,
        struct butterflyfish_ordered_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, swappable_settable_set_i,
                              ordered_settable_set_i);
    return 0;
}

const struct butterflyfish_swappable_settable_set_i swappable_settable_set_i = {
        .as_swappable_set = swappable_settable_set_as_swappable_set,
        .as_ordered_settable_set = swappable_settable_set_as_ordered_settable_set,
};

static int
swappable_incremental_set_as_swappable_set(
        struct butterflyfish_swappable_incremental_set_i *const object,
        struct butterflyfish_swappable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            swappable_incremental_set_i, swappable_set_i);
    return 0;
}

static int
swappable_incremental_set_as_ordered_incremental_set(
        struct butterflyfish_swappable_incremental_set_i *const object,
        struct butterflyfish_ordered_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            swappable_incremental_set_i, ordered_incremental_set_i);
    return 0;
}

const struct
butterflyfish_swappable_incremental_set_i swappable_incremental_set_i = {
        .as_swappable_set = swappable_incremental_set_as_swappable_set,
        .as_ordered_incremental_set =
                swappable_incremental_set_as_ordered_incremental_set,
};

static int
swappable_reducible_set_as_swappable_set(
        struct butterflyfish_swappable_reducible_set_i *const object,
        struct butterflyfish_swappable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            swappable_reducible_set_i, swappable_set_i);
    return 0;
}

static int
swappable_reducible_set_as_ordered_reducible_set(
        struct butterflyfish_swappable_reducible_set_i *const object,
        struct butterflyfish_ordered_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            swappable_reducible_set_i, ordered_reducible_set_i);
    return 0;
}

const struct
butterflyfish_swappable_reducible_set_i swappable_reducible_set_i = {
        .as_swappable_set = swappable_reducible_set_as_swappable_set,
        .as_ordered_reducible_set =
                swappable_reducible_set_as_ordered_reducible_set,
};

static int
swappable_settable_incremental_set_as_ordered_settable_set(
        struct butterflyfish_swappable_settable_incremental_set_i *const object,
        struct butterflyfish_ordered_settable_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              swappable_settable_incremental_set_i,
                              ordered_settable_incremental_set_i);
    return 0;
}

static int
swappable_settable_incremental_set_as_swappable_settable_set(
        struct butterflyfish_swappable_settable_incremental_set_i *const object,
        struct butterflyfish_swappable_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              swappable_settable_incremental_set_i,
                              swappable_settable_set_i);
    return 0;
}

static int
swappable_settable_incremental_set_as_swappable_incremental_set(
        struct butterflyfish_swappable_settable_incremental_set_i *const object,
        struct butterflyfish_swappable_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              swappable_settable_incremental_set_i,
                              swappable_incremental_set_i);
    return 0;
}

const struct butterflyfish_swappable_settable_incremental_set_i
swappable_settable_incremental_set_i = {
        .as_ordered_settable_incremental_set =
                swappable_settable_incremental_set_as_ordered_settable_set,
        .as_swappable_settable_set =
                swappable_settable_incremental_set_as_swappable_settable_set,
        .as_swappable_incremental_set =
                swappable_settable_incremental_set_as_swappable_incremental_set,
};

static int
swappable_settable_reducible_set_as_ordered_settable_reducible_set(
        struct butterflyfish_swappable_settable_reducible_set_i *const object,
        struct butterflyfish_ordered_settable_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              swappable_settable_reducible_set_i,
                              ordered_settable_reducible_set_i);
    return 0;
}

static int
swappable_settable_reducible_set_as_swappable_settable_set(
        struct butterflyfish_swappable_settable_reducible_set_i *const object,
        struct butterflyfish_swappable_settable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              swappable_settable_reducible_set_i,
                              swappable_settable_set_i);
    return 0;
}

static int
swappable_settable_reducible_set_as_swappable_reducible_set(
        struct butterflyfish_swappable_settable_reducible_set_i *const object,
        struct butterflyfish_swappable_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
                              swappable_settable_reducible_set_i,
                              swappable_reducible_set_i);
    return 0;
}

const struct
butterflyfish_swappable_settable_reducible_set_i
swappable_settable_reducible_set_i = {
        .as_ordered_settable_reducible_set =
                swappable_settable_reducible_set_as_ordered_settable_reducible_set,
        .as_swappable_settable_set =
                swappable_settable_reducible_set_as_swappable_settable_set,
        .as_swappable_reducible_set =
                swappable_settable_reducible_set_as_swappable_reducible_set
};

static int
swappable_mutable_set_as_ordered_mutable_set(
        struct butterflyfish_swappable_mutable_set_i *const object,
        struct butterflyfish_ordered_mutable_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            swappable_mutable_set_i, ordered_mutable_set_i);
    return 0;
}

static int
swappable_mutable_set_as_swappable_settable_incremental_set_i(
        struct butterflyfish_swappable_mutable_set_i *const object,
        struct butterflyfish_swappable_settable_incremental_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            swappable_mutable_set_i,
            swappable_settable_incremental_set_i);
    return 0;
}

static int
swappable_mutable_set_as_swappable_settable_reducible_set_i(
        struct butterflyfish_swappable_mutable_set_i *const object,
        struct butterflyfish_swappable_settable_reducible_set_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object,
            swappable_mutable_set_i,
            swappable_settable_reducible_set_i);
    return 0;
}

const struct
butterflyfish_swappable_mutable_set_i swappable_mutable_set_i = {
        .as_swappable_settable_incremental_set =
                swappable_mutable_set_as_swappable_settable_incremental_set_i,
        .as_swappable_settable_reducible_set =
                swappable_mutable_set_as_swappable_settable_reducible_set_i,
        .as_ordered_mutable_set = swappable_mutable_set_as_ordered_mutable_set,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_stream(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_stream(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_i);
    const struct butterflyfish_stream_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_stream(
            (const struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_collection(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_collection(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_collection(
            (const struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_addable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_addable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_addable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_addable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_addable(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance + offsetof(struct object, addable_i);
    struct butterflyfish_addable_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_addable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_removable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_removable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_removable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_removable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_removable(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, removable_i);
    struct butterflyfish_removable_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_removable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_i);
    struct butterflyfish_settable_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_settable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_i);
    const struct butterflyfish_ordered_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_ordered(
            (const struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_insertable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_insertable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_insertable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_insertable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_insertable(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, insertable_i);
    struct butterflyfish_insertable_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_insertable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_swappable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_swappable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_swappable(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_i);
    struct butterflyfish_swappable_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_swappable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_set(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_set((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_set(
            (const struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_reducible_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_reducible_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_reducible_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_reducible_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, reducible_set_i);
    struct butterflyfish_reducible_set_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_reducible_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, incremental_set_i);
    struct butterflyfish_incremental_set_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_incremental_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_settable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable_set(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_settable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable_set((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_set_i);
    struct butterflyfish_settable_set_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_settable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_settable_reducible_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable_reducible_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_settable_reducible_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable_reducible_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_reducible_set_i);
    struct butterflyfish_settable_reducible_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable_reducible_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_settable_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_settable_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_settable_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_incremental_set_i);
    struct butterflyfish_settable_incremental_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable_incremental_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_mutable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_mutable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_mutable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_mutable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_mutable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, mutable_set_i);
    struct butterflyfish_mutable_set_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_mutable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_set_i);
    const struct butterflyfish_ordered_set_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_ordered_set(
            (const struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_swappable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_swappable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_swappable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_set_i);
    struct butterflyfish_swappable_set_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_swappable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_ordered_reducible_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_reducible_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_ordered_reducible_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_reducible_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_reducible_set_i);
    struct butterflyfish_ordered_reducible_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_ordered_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_ordered_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_incremental_set_i);
    struct butterflyfish_ordered_incremental_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_settable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_settable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_settable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_settable_set_i);
    struct butterflyfish_ordered_settable_set_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_ordered_settable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_ordered_settable_reducible_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_reducible_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_ordered_settable_reducible_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_reducible_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_settable_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_settable_reducible_set_i);
    struct butterflyfish_ordered_settable_reducible_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_ordered_settable_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_ordered_settable_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_settable_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_settable_incremental_set_i);
    struct butterflyfish_ordered_settable_incremental_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_ordered_mutable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_mutable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_ordered_mutable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_mutable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_mutable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_mutable_set_i);
    struct butterflyfish_ordered_mutable_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_mutable_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_swappable_reducible_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_reducible_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_swappable_reducible_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_reducible_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_swappable_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_reducible_set_i);
    struct butterflyfish_swappable_reducible_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_swappable_incremental_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_swappable_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_swappable_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_incremental_set_i);
    struct butterflyfish_swappable_incremental_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_swappable_settable_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_swappable_settable_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_swappable_settable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_settable_set_i);
    struct butterflyfish_swappable_settable_set_i *out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_swappable_settable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_swappable_settable_reducible_set_error_on_object_is_null(
        void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_reducible_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_swappable_settable_reducible_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_reducible_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_swappable_settable_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_settable_reducible_set_i);
    struct butterflyfish_swappable_settable_reducible_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_as_swappable_settable_incremental_set_error_on_object_is_null(
        void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_incremental_set(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void
check_as_swappable_settable_incremental_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_incremental_set(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_as_swappable_settable_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_settable_incremental_set_i);
    struct butterflyfish_swappable_settable_incremental_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_swappable_settable_set_as_swapped_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_set_i);
    struct butterflyfish_swappable_settable_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_swappable_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_settable_set_i_as_swappable_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_swappable_settable_set_as_ordered_settable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_settable_set_i);
    struct butterflyfish_swappable_settable_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_ordered_settable_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_settable_set_i_as_ordered_settable_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_swappable_settable_reducible_set_as_swappable_settable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_settable_set_i);
    struct butterflyfish_swappable_settable_reducible_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_settable_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_swappable_settable_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_settable_reducible_set_i_as_swappable_settable_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_swappable_incremental_set_as_swappable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_set_i);
    struct butterflyfish_swappable_incremental_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_swappable_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_incremental_set_i_as_swappable_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_swappable_incremental_set_as_ordered_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_incremental_set_i);
    struct butterflyfish_swappable_incremental_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_ordered_incremental_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_incremental_set_i_as_ordered_incremental_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_swappable_reducible_set_as_swappable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_set_i);
    struct butterflyfish_swappable_reducible_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_swappable_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_reducible_set_i_as_swappable_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_swappable_reducible_set_as_ordered_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_reducible_set_i);
    struct butterflyfish_swappable_reducible_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_swappable_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_ordered_reducible_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_reducible_set_i_as_ordered_reducible_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_ordered_settable_reducible_set_as_ordered_settable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_settable_set_i);
    struct butterflyfish_ordered_settable_reducible_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_ordered_settable_set_i *out;
    assert_int_equal(
            butterflyfish_ordered_settable_reducible_set_i_as_ordered_settable_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_ordered_settable_reducible_set_as_settable_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_reducible_set_i);
    struct butterflyfish_ordered_settable_reducible_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_settable_reducible_set_i *out;
    assert_int_equal(
            butterflyfish_ordered_settable_reducible_set_i_as_settable_reducible_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_ordered_settable_incremental_set_as_settable_incremental_set(
        void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_incremental_set_i);
    struct butterflyfish_ordered_settable_incremental_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_settable_incremental_set_i *out;
    assert_int_equal(
            butterflyfish_ordered_settable_incremental_set_i_as_settable_incremental_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_settable_set_as_ordered_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_set_i);
    struct butterflyfish_ordered_settable_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    const struct butterflyfish_ordered_set_i *out;
    assert_int_equal(
            butterflyfish_ordered_settable_set_i_as_ordered_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_settable_set_as_settable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_set_i);
    struct butterflyfish_ordered_settable_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_settable_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_settable_set_i *out;
    assert_int_equal(
            butterflyfish_ordered_settable_set_i_as_settable_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_incremental_set_as_insertable(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, insertable_i);
    struct butterflyfish_ordered_incremental_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_insertable_i *out;
    assert_int_equal(
            butterflyfish_ordered_incremental_set_i_as_insertable(as, &out),
            0);
    assert_ptr_equal(out, check);
}

static void check_ordered_incremental_set_as_ordered_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_set_i);
    struct butterflyfish_ordered_incremental_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    const struct butterflyfish_ordered_set_i *out;
    assert_int_equal(
            butterflyfish_ordered_incremental_set_i_as_ordered_set(as, &out),
            0);
    assert_ptr_equal(out, check);
}

static void check_ordered_incremental_set_as_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, incremental_set_i);
    struct butterflyfish_ordered_incremental_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_incremental_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_incremental_set_i *out;
    assert_int_equal(
            butterflyfish_ordered_incremental_set_i_as_incremental_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_reducible_set_as_ordered_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_set_i);
    struct butterflyfish_ordered_reducible_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    const struct butterflyfish_ordered_set_i *out;
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_ordered_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_reducible_set_as_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, reducible_set_i);
    struct butterflyfish_ordered_reducible_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_reducible_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance, &as), 0);
    struct butterflyfish_reducible_set_i *out;
    assert_int_equal(
            butterflyfish_ordered_reducible_set_i_as_reducible_set(
                    as, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_ordered_mutable_set_as_ordered_settable_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_settable_reducible_set_i);
    struct butterflyfish_ordered_mutable_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_mutable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    struct butterflyfish_ordered_settable_reducible_set_i *out;
    assert_int_equal(butterflyfish_ordered_mutable_set_i_as_ordered_settable_reducible_set(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_ordered_mutable_set_as_ordered_settable_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_settable_incremental_set_i);
    struct butterflyfish_ordered_mutable_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_ordered_mutable_set(
                    (struct butterflyfish_swappable_mutable_set_i *)
                            &instance,&as), 0);
    struct butterflyfish_ordered_settable_incremental_set_i *out;
    assert_int_equal(butterflyfish_ordered_mutable_set_i_as_ordered_settable_incremental_set(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_mutable_set_as_settable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, settable_set_i);
    struct butterflyfish_mutable_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_mutable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    struct butterflyfish_settable_set_i *out;
    assert_int_equal(butterflyfish_mutable_set_i_as_settable_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_mutable_set_as_incremental_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, incremental_set_i);
    struct butterflyfish_mutable_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_mutable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    struct butterflyfish_incremental_set_i *out;
    assert_int_equal(
            butterflyfish_mutable_set_i_as_incremental_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_mutable_set_as_reducible_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, reducible_set_i);
    struct butterflyfish_mutable_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_mutable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    struct butterflyfish_reducible_set_i *out;
    assert_int_equal(
            butterflyfish_mutable_set_i_as_reducible_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_swappable_set_as_swappable(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, swappable_i);
    struct butterflyfish_swappable_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_swappable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    struct butterflyfish_swappable_i *out;
    assert_int_equal(
            butterflyfish_swappable_set_i_as_swappable(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_swappable_set_as_ordered_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_set_i);
    struct butterflyfish_swappable_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_swappable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    const struct butterflyfish_ordered_set_i *out;
    assert_int_equal(
            butterflyfish_swappable_set_i_as_ordered_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_set_as_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    const struct butterflyfish_ordered_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_ordered_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_ordered_set_i_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void
check_settable_reducible_set_as_settable_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, settable_set_i);
    struct butterflyfish_settable_reducible_set_i *as;
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_as_settable_reducible_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    struct butterflyfish_settable_set_i *out;
    assert_int_equal(butterflyfish_settable_reducible_set_i_as_settable_set(
            as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_set_as_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    struct butterflyfish_settable_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_settable_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_settable_set_i_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_incremental_set_as_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    struct butterflyfish_incremental_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_incremental_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_incremental_set_i_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_reducible_set_as_set(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance + offsetof(struct object, set_i);
    struct butterflyfish_reducible_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_reducible_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    const struct butterflyfish_set_i *out;
    assert_int_equal(butterflyfish_reducible_set_i_as_set(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_reducible_set_as_removable(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, removable_i);
    struct butterflyfish_reducible_set_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_reducible_set(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &as), 0);
    struct butterflyfish_removable_i *out;
    assert_int_equal(butterflyfish_reducible_set_i_as_removable(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_swappable_as_ordered(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance + offsetof(struct object, ordered_i);
    struct butterflyfish_swappable_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_swappable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    const struct butterflyfish_ordered_i *out;
    assert_int_equal(butterflyfish_swappable_i_as_ordered(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_insertable_as_ordered(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance + offsetof(struct object, ordered_i);
    struct butterflyfish_insertable_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_insertable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &as), 0);
    const struct butterflyfish_ordered_i *out;
    assert_int_equal(butterflyfish_insertable_i_as_ordered(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_as_collection(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i);
    const struct butterflyfish_ordered_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_ordered(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_ordered_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_settable_as_collection(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    struct butterflyfish_settable_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_settable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_settable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_removable_as_collection(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i);
    struct butterflyfish_removable_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_removable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_removable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_addable_as_collection(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    struct butterflyfish_addable_i *as;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_as_addable(
            (struct butterflyfish_swappable_mutable_set_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_addable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_count((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_swappable_mutable_set_i_count(
            (const struct butterflyfish_swappable_mutable_set_i *) &instance,
            &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_first((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_first(
                    (const struct butterflyfish_swappable_mutable_set_i *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_last((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_last(
                    (const struct butterflyfish_swappable_mutable_set_i *)
                            &instance, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_next(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_next(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_next(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_next(
                    (const struct butterflyfish_swappable_mutable_set_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_prev(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_prev(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_prev(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_prev(
                    (const struct butterflyfish_swappable_mutable_set_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_contains(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_contains(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_contains(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(set_contains);
    will_return(set_contains,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_contains(
                    (const struct butterflyfish_swappable_mutable_set_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_contains_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_contains_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_contains_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(set_contains_all);
    will_return(set_contains_all,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_contains_all(
                    (const struct butterflyfish_swappable_mutable_set_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_get(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_get(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_get(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_value_not_found(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_get(
                    (const struct butterflyfish_swappable_mutable_set_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_get(
                    (const struct butterflyfish_swappable_mutable_set_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set_item(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set_item(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_set_item_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set_item(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_set_item_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set_item(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_item_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set_item(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_item_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set_item(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_set_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_set_error_on_value_not_found(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_set_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_set(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_add(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_add((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_add_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_add(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID);
}

static void check_add_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_add(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_add(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_add_all((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(addable_add_all);
    will_return(addable_add_all,
                BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_add_all(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_insert_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_insert_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_insert_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_insert_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID);
}

static void check_insert_error_on_value_already_exists(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_insert_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_insert_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_insert_all_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_insert_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_insert_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(insertable_insert_all);
    will_return(insertable_insert_all,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_insert_all(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove_item(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove_item((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_remove_item(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(removable_remove_item);
    will_return(removable_remove_item, 0);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove_item(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1), 0);
}

static void check_remove_all_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove_all_items(
                    NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_items_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove_all_items(
                    (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_items(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(removable_remove_all_items);
    will_return(removable_remove_all_items, 0);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove_all_items(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1), 0);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_remove_error_on_value_not_found(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(reducible_set_remove);
    will_return(reducible_set_remove,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(reducible_set_remove);
    will_return(reducible_set_remove,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(reducible_set_remove_all);
    will_return(reducible_set_remove_all,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_remove_all(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void
check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(reducible_set_retain_all);
    will_return(reducible_set_retain_all,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_retain_all(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_swap_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_swap(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_swap_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_swap(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_swap_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_swap(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_swap(void **state) {
    const struct object instance = {
            .swappable_mutable_set_i = &swappable_mutable_set_i,
            .swappable_settable_incremental_set_i =
                    &swappable_settable_incremental_set_i,
            .swappable_settable_reducible_set_i =
                    &swappable_settable_reducible_set_i,
            .swappable_reducible_set_i = &swappable_reducible_set_i,
            .swappable_incremental_set_i = &swappable_incremental_set_i,
            .swappable_settable_set_i = &swappable_settable_set_i,
            .ordered_mutable_set_i = &ordered_mutable_set_i,
            .ordered_settable_incremental_set_i =
                    &ordered_settable_incremental_set_i,
            .ordered_settable_reducible_set_i =
                    &ordered_settable_reducible_set_i,
            .ordered_reducible_set_i = &ordered_reducible_set_i,
            .ordered_incremental_set_i = &ordered_incremental_set_i,
            .ordered_settable_set_i = &ordered_settable_set_i,
            .ordered_set_i = &ordered_set_i,
            .mutable_set_i = &mutable_set_i,
            .settable_incremental_set_i = &settable_incremental_set_i,
            .settable_reducible_set_i = &settable_reducible_set_i,
            .reducible_set_i = &reducible_set_i,
            .incremental_set_i = &incremental_set_i,
            .settable_set_i = &settable_set_i,
            .swappable_set_i = &swappable_set_i,
            .set_i = &set_i,
            .swappable_i = &swappable_i,
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .settable_i = &settable_i,
            .removable_i = &removable_i,
            .addable_i = &addable_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i,
    };
    expect_function_call(swappable_swap);
    will_return(swappable_swap, 0);
    assert_int_equal(
            butterflyfish_swappable_mutable_set_i_swap(
                    (struct butterflyfish_swappable_mutable_set_i *) &instance,
                    (void *) 1,
                    (void *) 1), 0);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_addable_error_on_object_is_null),
            cmocka_unit_test(check_as_addable_error_on_out_is_null),
            cmocka_unit_test(check_as_addable),
            cmocka_unit_test(check_as_removable_error_on_object_is_null),
            cmocka_unit_test(check_as_removable_error_on_out_is_null),
            cmocka_unit_test(check_as_removable),
            cmocka_unit_test(check_as_settable_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_error_on_out_is_null),
            cmocka_unit_test(check_as_settable),
            cmocka_unit_test(check_as_ordered_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered),
            cmocka_unit_test(check_as_insertable_error_on_object_is_null),
            cmocka_unit_test(check_as_insertable_error_on_out_is_null),
            cmocka_unit_test(check_as_insertable),
            cmocka_unit_test(check_as_swappable_error_on_object_is_null),
            cmocka_unit_test(check_as_swappable_error_on_out_is_null),
            cmocka_unit_test(check_as_swappable),
            cmocka_unit_test(check_as_set_error_on_object_is_null),
            cmocka_unit_test(check_as_set_error_on_out_is_null),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_as_reducible_set_error_on_object_is_null),
            cmocka_unit_test(check_as_reducible_set_error_on_out_is_null),
            cmocka_unit_test(check_as_reducible_set),
            cmocka_unit_test(check_as_incremental_set_error_on_object_is_null),
            cmocka_unit_test(check_as_incremental_set_error_on_out_is_null),
            cmocka_unit_test(check_as_incremental_set),
            cmocka_unit_test(check_as_settable_set_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_set_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_set),
            cmocka_unit_test(check_as_settable_reducible_set_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_reducible_set_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_reducible_set),
            cmocka_unit_test(check_as_settable_incremental_set_error_on_object_is_null),
            cmocka_unit_test(check_as_settable_incremental_set_error_on_out_is_null),
            cmocka_unit_test(check_as_settable_incremental_set),
            cmocka_unit_test(check_as_mutable_set_error_on_object_is_null),
            cmocka_unit_test(check_as_mutable_set_error_on_out_is_null),
            cmocka_unit_test(check_as_mutable_set),
            cmocka_unit_test(check_as_ordered_set_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_set_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_set),
            cmocka_unit_test(check_as_swappable_set_error_on_object_is_null),
            cmocka_unit_test(check_as_swappable_set_error_on_out_is_null),
            cmocka_unit_test(check_as_swappable_set),
            cmocka_unit_test(check_as_ordered_reducible_set_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_reducible_set_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_reducible_set),
            cmocka_unit_test(check_as_ordered_incremental_set_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_incremental_set_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_incremental_set),
            cmocka_unit_test(check_as_ordered_settable_set_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_settable_set_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_settable_set),
            cmocka_unit_test(check_as_ordered_settable_reducible_set_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_settable_reducible_set_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_settable_reducible_set),
            cmocka_unit_test(check_as_ordered_settable_incremental_set_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_settable_incremental_set_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_settable_incremental_set),
            cmocka_unit_test(check_as_ordered_mutable_set_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_mutable_set_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_mutable_set),
            cmocka_unit_test(check_as_swappable_reducible_set_error_on_object_is_null),
            cmocka_unit_test(check_as_swappable_reducible_set_error_on_out_is_null),
            cmocka_unit_test(check_as_swappable_reducible_set),
            cmocka_unit_test(check_as_swappable_incremental_set_error_on_object_is_null),
            cmocka_unit_test(check_as_swappable_incremental_set_error_on_out_is_null),
            cmocka_unit_test(check_as_swappable_incremental_set),
            cmocka_unit_test(check_as_swappable_settable_set_error_on_object_is_null),
            cmocka_unit_test(check_as_swappable_settable_set_error_on_out_is_null),
            cmocka_unit_test(check_as_swappable_settable_set),
            cmocka_unit_test(check_as_swappable_settable_reducible_set_error_on_object_is_null),
            cmocka_unit_test(check_as_swappable_settable_reducible_set_error_on_out_is_null),
            cmocka_unit_test(check_as_swappable_settable_reducible_set),
            cmocka_unit_test(check_as_swappable_settable_incremental_set_error_on_object_is_null),
            cmocka_unit_test(check_as_swappable_settable_incremental_set_error_on_out_is_null),
            cmocka_unit_test(check_as_swappable_settable_incremental_set),
            cmocka_unit_test(check_swappable_settable_set_as_swapped_set),
            cmocka_unit_test(check_swappable_settable_set_as_ordered_settable_set),
            cmocka_unit_test(check_swappable_settable_reducible_set_as_swappable_settable_set),
            cmocka_unit_test(check_swappable_incremental_set_as_swappable_set),
            cmocka_unit_test(check_swappable_incremental_set_as_ordered_incremental_set),
            cmocka_unit_test(check_swappable_reducible_set_as_swappable_set),
            cmocka_unit_test(check_swappable_reducible_set_as_ordered_reducible_set),
            cmocka_unit_test(check_ordered_settable_reducible_set_as_ordered_settable_set),
            cmocka_unit_test(check_ordered_settable_reducible_set_as_settable_reducible_set),
            cmocka_unit_test(check_ordered_settable_incremental_set_as_settable_incremental_set),
            cmocka_unit_test(check_ordered_settable_set_as_ordered_set),
            cmocka_unit_test(check_ordered_settable_set_as_settable_set),
            cmocka_unit_test(check_ordered_incremental_set_as_insertable),
            cmocka_unit_test(check_ordered_incremental_set_as_ordered_set),
            cmocka_unit_test(check_ordered_incremental_set_as_incremental_set),
            cmocka_unit_test(check_ordered_reducible_set_as_ordered_set),
            cmocka_unit_test(check_ordered_reducible_set_as_reducible_set),
            cmocka_unit_test(check_ordered_mutable_set_as_ordered_settable_reducible_set),
            cmocka_unit_test(check_ordered_mutable_set_as_ordered_settable_incremental_set),
            cmocka_unit_test(check_mutable_set_as_settable_set),
            cmocka_unit_test(check_mutable_set_as_incremental_set),
            cmocka_unit_test(check_mutable_set_as_reducible_set),
            cmocka_unit_test(check_swappable_set_as_swappable),
            cmocka_unit_test(check_swappable_set_as_ordered_set),
            cmocka_unit_test(check_ordered_set_as_set),
            cmocka_unit_test(check_settable_reducible_set_as_settable_set),
            cmocka_unit_test(check_settable_set_as_set),
            cmocka_unit_test(check_incremental_set_as_set),
            cmocka_unit_test(check_reducible_set_as_set),
            cmocka_unit_test(check_reducible_set_as_removable),
            cmocka_unit_test(check_swappable_as_ordered),
            cmocka_unit_test(check_insertable_as_ordered),
            cmocka_unit_test(check_ordered_as_collection),
            cmocka_unit_test(check_settable_as_collection),
            cmocka_unit_test(check_removable_as_collection),
            cmocka_unit_test(check_addable_as_collection),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_set_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_set_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_contains_error_on_object_is_null),
            cmocka_unit_test(check_contains_error_on_value_is_null),
            cmocka_unit_test(check_contains_error_on_out_is_null),
            cmocka_unit_test(check_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_value_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_value_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_item_error_on_object_is_null),
            cmocka_unit_test(check_set_item_error_on_item_is_null),
            cmocka_unit_test(check_set_item_error_on_value_is_null),
            cmocka_unit_test(check_set_item_error_on_value_is_invalid),
            cmocka_unit_test(check_set_item_error_on_value_already_exists),
            cmocka_unit_test(check_set_item_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_error_on_object_is_null),
            cmocka_unit_test(check_set_error_on_item_is_null),
            cmocka_unit_test(check_set_error_on_value_is_null),
            cmocka_unit_test(check_set_error_on_value_not_found),
            cmocka_unit_test(check_set_error_on_value_is_invalid),
            cmocka_unit_test(check_set_error_on_value_already_exists),
            cmocka_unit_test(check_set_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_value_is_invalid),
            cmocka_unit_test(check_add_error_on_value_already_exists),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_insert_error_on_object_is_null),
            cmocka_unit_test(check_insert_error_on_item_is_null),
            cmocka_unit_test(check_insert_error_on_value_is_null),
            cmocka_unit_test(check_insert_error_on_value_is_invalid),
            cmocka_unit_test(check_insert_error_on_value_already_exists),
            cmocka_unit_test(check_insert_error_on_memory_allocation_failed),
            cmocka_unit_test(check_insert_all_error_on_object_is_null),
            cmocka_unit_test(check_insert_all_error_on_item_is_null),
            cmocka_unit_test(check_insert_all_error_on_other_is_null),
            cmocka_unit_test(check_insert_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
            cmocka_unit_test(check_remove_item),
            cmocka_unit_test(check_remove_all_items_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_items_error_on_item_is_null),
            cmocka_unit_test(check_remove_all_items),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_value_is_null),
            cmocka_unit_test(check_remove_error_on_value_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_other_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_retain_all_error_on_object_is_null),
            cmocka_unit_test(check_retain_all_error_on_other_is_null),
            cmocka_unit_test(check_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_swap_error_on_object_is_null),
            cmocka_unit_test(check_swap_error_on_item_is_null),
            cmocka_unit_test(check_swap_error_on_other_is_null),
            cmocka_unit_test(check_swap),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
