#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <seagrass.h>
#include <test/cmocka.h>

struct instance {
    const struct butterflyfish_mutable_map_i_i *const id;
    void *data;
};

const struct butterflyfish_mutable_map_i_i mutable_map_i_i;

static int stream_first(const void *const object,
                        const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

static int stream_next(const void *const object,
                       const struct butterflyfish_map_i_i_entry *const item,
                       const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

const struct butterflyfish_stream_i_i stream_i_i = {
        .first = stream_first,
        .next = stream_next
};

static int
collection_last(const void *const object,
                const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

static int
collection_prev(const void *const object,
                const struct butterflyfish_map_i_i_entry *const item,
                const struct butterflyfish_map_i_i_entry **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

static int
collection_count(const void *const object, uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_i_i collection_i_i = {
        .as_stream = &stream_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

const struct butterflyfish_set_i_i set_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

static int
map_contains_key(const void *const object,
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
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

static int
map_contains_value(const void *const object,
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
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

static int map_get(const void *const object,
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
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

static int
map_get_entry(const void *const object,
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
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

const struct butterflyfish_map_i_i map_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .as_set = &set_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .get = map_get,
        .get_entry = map_get_entry,
        .keys = (void *) 1,
        .values = (void *) 1,
};

static int
settable_set_item(void *const object,
                  const struct butterflyfish_map_i_i_entry *const item,
                  const struct butterflyfish_map_i_i_entry *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_I_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

const struct butterflyfish_settable_i_i settable_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .set_item = settable_set_item,
};

static int
settable_map_set(void *const object,
                 const struct sea_turtle_integer *const key,
                 const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

static int settable_map_set_key(void *const object,
                                const struct sea_turtle_integer *const key,
                                const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

const struct butterflyfish_settable_map_i_i settable_map_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .as_set = &set_i_i,
        .as_settable = &settable_i_i,
        .as_map = &map_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .get = map_get,
        .get_entry = map_get_entry,
        .set = &settable_map_set,
        .set_entry = &settable_set_item,
        .set_key = &settable_map_set_key,
        .keys = (void *) 1,
        .values = (void *) 1,
};

const struct butterflyfish_addable_i_i addable_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .add = NULL
};

static int
incremental_map_add(void *const object,
                    const struct sea_turtle_integer *const key,
                    const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

const struct butterflyfish_incremental_map_i_i incremental_map_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .as_set = &set_i_i,
        .as_map = &map_i_i,
        .as_addable = &addable_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .add = incremental_map_add,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .get = map_get,
        .get_entry = map_get_entry,
        .keys = (void *) 1,
        .values = (void *) 1,
};

const struct
butterflyfish_settable_incremental_map_i_i settable_incremental_map_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .as_set = &set_i_i,
        .as_map = &map_i_i,
        .as_addable = &addable_i_i,
        .as_settable = &settable_i_i,
        .as_settable_map = &settable_map_i_i,
        .as_incremental_map = &incremental_map_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .add = incremental_map_add,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .get = map_get,
        .get_entry = map_get_entry,
        .set = &settable_map_set,
        .set_entry = &settable_set_item,
        .set_key = &settable_map_set_key,
        .keys = (void *) 1,
        .values = (void *) 1,
};

const struct butterflyfish_removable_i_i removable_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .remove_item = NULL,
};

static int
reducible_map_remove(void *const object,
                     const struct sea_turtle_integer *const key) {
    if (!object) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL;
    }
    if (!key) {
        return BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&mutable_map_i_i == instance->id);
    return mock();
}

const struct butterflyfish_reducible_map_i_i reducible_map_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .as_set = &set_i_i,
        .as_map = &map_i_i,
        .as_removable = &removable_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .get = map_get,
        .get_entry = map_get_entry,
        .remove = reducible_map_remove,
        .keys = (void *) 1,
        .values = (void *) 1,
};

const struct
butterflyfish_settable_reducible_map_i_i settable_reducible_map_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .as_set = &set_i_i,
        .as_map = &map_i_i,
        .as_settable = &settable_i_i,
        .as_removable = &removable_i_i,
        .as_settable_map = &settable_map_i_i,
        .as_reducible_map = &reducible_map_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .get = map_get,
        .get_entry = map_get_entry,
        .set = &settable_map_set,
        .set_entry = &settable_set_item,
        .set_key = &settable_map_set_key,
        .remove = reducible_map_remove,
        .keys = (void *) 1,
        .values = (void *) 1,
};

const struct butterflyfish_mutable_map_i_i mutable_map_i_i = {
        .as_stream = &stream_i_i,
        .as_collection = &collection_i_i,
        .as_set = &set_i_i,
        .as_map = &map_i_i,
        .as_settable = &settable_i_i,
        .as_removable = &removable_i_i,
        .as_addable = &addable_i_i,
        .as_settable_map = &settable_map_i_i,
        .as_reducible_map = &reducible_map_i_i,
        .as_incremental_map = &incremental_map_i_i,
        .as_settable_reducible_map = &settable_reducible_map_i_i,
        .as_settable_incremental_map = &settable_incremental_map_i_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains_key = map_contains_key,
        .contains_value = map_contains_value,
        .get = map_get,
        .get_entry = map_get_entry,
        .set = &settable_map_set,
        .set_entry = &settable_set_item,
        .set_key = &settable_map_set_key,
        .add = incremental_map_add,
        .remove = reducible_map_remove,
        .keys = (void *) 1,
        .values = (void *) 1,
};

static void check_as_stream(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_stream, &stream_i_i);
}

static void check_as_collection(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_collection, &collection_i_i);
}

static void check_as_set(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_set, &set_i_i);
}

static void check_as_map(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_map, &map_i_i);
}

static void check_as_addable(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_addable, &addable_i_i);
}

static void check_as_removable(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_removable, &removable_i_i);
}

static void check_as_settable(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_settable, &settable_i_i);
}

static void check_as_incremental_map(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_incremental_map, &incremental_map_i_i);
}

static void check_as_reducible_map(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_reducible_map, &reducible_map_i_i);
}

static void check_as_settable_map(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_settable_map, &settable_map_i_i);
}

static void check_as_settable_incremental_map(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_settable_incremental_map,
                     &settable_incremental_map_i_i);
}

static void check_as_settable_reducible_map(void **state) {
    assert_ptr_equal(mutable_map_i_i.as_settable_reducible_map,
                     &settable_reducible_map_i_i);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.count(NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.count((void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(instance.id->count(&instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.first(NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.first((void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_map_is_empty(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(instance.id->first(&instance, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.last(NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.last((void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_map_is_empty(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(instance.id->last(&instance, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.next(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.next((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.next((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->next(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.prev(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.prev((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.prev((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->prev(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_contains_key_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.contains_key(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_key_error_on_key_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.contains_key((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_contains_key_error_on_out_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.contains_key((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_contains_key_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(map_contains_key);
    will_return(map_contains_key,
                BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->contains_key(&instance, (void *) 1,(void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_value_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.contains_value(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_value_error_on_value_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.contains_value((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_contains_value_error_on_out_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.contains_value((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_contains_value_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(map_contains_value);
    will_return(map_contains_value,
                BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->contains_value(&instance, (void *) 1,(void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.get(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_key_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.get((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_ENTRY_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.get((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_key_not_found(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(map_get);
    will_return(map_get,
                BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(instance.id->get(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(map_get);
    will_return(map_get,
                BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->get(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_entry_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.get_entry(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_entry_error_on_key_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.get_entry((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_get_entry_error_on_out_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.get_entry((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_get_entry_error_on_key_not_found(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(map_get_entry);
    will_return(map_get_entry,
                BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(instance.id->get_entry(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_get_entry_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(map_get_entry);
    will_return(map_get_entry,
                BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->get_entry(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.set(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_error_on_key_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.set((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_set_error_on_value_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.set((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_set_error_on_key_not_found(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(settable_map_set);
    will_return(settable_map_set,
                BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(instance.id->set(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_set_error_on_value_is_invalid(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(settable_map_set);
    will_return(settable_map_set,
                BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(instance.id->set(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(settable_map_set);
    will_return(settable_map_set,
                BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->set(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_key_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.set_key(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_key_error_on_key_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.set_key((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_set_key_error_on_value_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.set_key((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_set_key_error_on_key_not_found(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(settable_map_set_key);
    will_return(settable_map_set_key,
                BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(instance.id->set_key(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_set_key_error_on_key_already_exists(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(settable_map_set_key);
    will_return(settable_map_set_key,
                BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(instance.id->set_key(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
}

static void check_set_key_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(settable_map_set_key);
    will_return(settable_map_set_key,
                BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->set_key(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_entry_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.set_entry(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_entry_error_on_key_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.set_entry((void *) 1, NULL,(void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_set_entry_error_on_value_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.set_entry((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_set_entry_error_on_key_already_exists(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(instance.id->set_entry(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
}

static void check_set_entry_error_on_value_is_invalid(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(instance.id->set_entry(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_entry_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->set_entry(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.add(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_key_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.add((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.add((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_add_error_value_is_invalid(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(incremental_map_add);
    will_return(incremental_map_add,
                BUTTERFLYFISH_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(mutable_map_i_i.add(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID);
}

static void check_add_error_key_already_exists(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(incremental_map_add);
    will_return(incremental_map_add,
                BUTTERFLYFISH_INCREMENTAL_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(instance.id->add(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
}

static void check_add_error_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(incremental_map_add);
    will_return(incremental_map_add,
                BUTTERFLYFISH_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->add(&instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.remove(NULL, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_key_is_null(void **state) {
    assert_int_equal(mutable_map_i_i.remove((void *) 1, NULL),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_remove_error_on_key_not_found(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(reducible_map_remove);
    will_return(reducible_map_remove,
                BUTTERFLYFISH_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(instance.id->remove(&instance, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &mutable_map_i_i,
    };
    expect_function_call(reducible_map_remove);
    will_return(reducible_map_remove,
                BUTTERFLYFISH_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->remove(&instance, (void *) 1),
                     BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_keys(void **state) {
    assert_ptr_equal(mutable_map_i_i.keys, (void *) 1);
}

static void check_values(void **state) {
    assert_ptr_equal(mutable_map_i_i.values, (void *) 1);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_as_map),
            cmocka_unit_test(check_as_addable),
            cmocka_unit_test(check_as_removable),
            cmocka_unit_test(check_as_settable),
            cmocka_unit_test(check_as_incremental_map),
            cmocka_unit_test(check_as_reducible_map),
            cmocka_unit_test(check_as_settable_map),
            cmocka_unit_test(check_as_settable_incremental_map),
            cmocka_unit_test(check_as_settable_reducible_map),
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
            cmocka_unit_test(check_contains_key_error_on_object_is_null),
            cmocka_unit_test(check_contains_key_error_on_key_is_null),
            cmocka_unit_test(check_contains_key_error_on_out_is_null),
            cmocka_unit_test(check_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_value_error_on_object_is_null),
            cmocka_unit_test(check_contains_value_error_on_value_is_null),
            cmocka_unit_test(check_contains_value_error_on_out_is_null),
            cmocka_unit_test(check_contains_value_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_key_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_key_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_is_null),
            cmocka_unit_test(check_get_entry_error_on_out_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_error_on_object_is_null),
            cmocka_unit_test(check_set_error_on_key_is_null),
            cmocka_unit_test(check_set_error_on_value_is_null),
            cmocka_unit_test(check_set_error_on_key_not_found),
            cmocka_unit_test(check_set_error_on_value_is_invalid),
            cmocka_unit_test(check_set_error_on_memory_allocation_failed),
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
            cmocka_unit_test(check_add_error_on_key_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_value_is_invalid),
            cmocka_unit_test(check_add_error_key_already_exists),
            cmocka_unit_test(check_add_error_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_key_is_null),
            cmocka_unit_test(check_remove_error_on_key_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_keys),
            cmocka_unit_test(check_values),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
