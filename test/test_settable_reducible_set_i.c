#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <seagrass.h>
#include <test/cmocka.h>

struct instance {
    const struct butterflyfish_settable_reducible_set_i *const id;
};

const struct butterflyfish_settable_reducible_set_i settable_reducible_set_i;
static int stream_first(const void *const object,
                        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

static int stream_next(const void *const object,
                       const struct sea_turtle_integer *const item,
                       const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

const struct butterflyfish_stream_i stream_i = {
        .first = stream_first,
        .next = stream_next
};

static int
collection_last(const void *const object,
                const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

static int
collection_prev(const void *const object,
                const struct sea_turtle_integer *const item,
                const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

static int
collection_count(const void *const object, uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_i collection_i = {
        .as_stream = &stream_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

static int
settable_set_item(void *const object,
                  const struct sea_turtle_integer *const item,
                  const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_I_ERROR_VALUE_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

const struct butterflyfish_settable_i settable_i = {
        .as_stream = &stream_i,
        .as_collection = &collection_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .set_item = settable_set_item,
};

static int set_contains(const void *const object,
                        const struct sea_turtle_integer *const value,
                        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

static int set_get(const void *const object,
                   const struct sea_turtle_integer *const value,
                   const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

const struct butterflyfish_set_i set_i = {
        .as_stream = &stream_i,
        .as_collection = &collection_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains = set_contains,
        .get = set_get,
};

static int
settable_set_set(void *const object,
                 const struct sea_turtle_integer *const item,
                 const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_SETTABLE_SET_I_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

const struct butterflyfish_settable_set_i settable_set_i = {
        .as_stream = &stream_i,
        .as_collection = &collection_i,
        .as_set = &set_i,
        .as_settable = &settable_set_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains = set_contains,
        .get = set_get,
        .set_item = settable_set_item,
        .set = settable_set_set,
};

static int
reducible_remove_item(void *const object,
                      const struct sea_turtle_integer *const item) {
    if (!object) {
        return BUTTERFLYFISH_REMOVABLE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REMOVABLE_I_ERROR_ITEM_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

const struct butterflyfish_removable_i removable_i = {
        .as_stream = &stream_i,
        .as_collection = &collection_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .remove_item = reducible_remove_item,
};

static int
reducible_set_remove(void *const object,
                     const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_VALUE_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&settable_reducible_set_i == instance->id);
    return mock();
}

const struct butterflyfish_reducible_set_i reducible_set_i = {
        .as_stream = &stream_i,
        .as_collection = &collection_i,
        .as_set = &set_i,
        .as_removable = &removable_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains = set_contains,
        .get = set_get,
        .remove_item = reducible_remove_item,
        .remove = reducible_set_remove,
};

const struct
butterflyfish_settable_reducible_set_i settable_reducible_set_i = {
        .as_stream = &stream_i,
        .as_collection = &collection_i,
        .as_set = &set_i,
        .as_removable = &removable_i,
        .as_settable = &settable_i,
        .as_settable_set = &settable_set_i,
        .as_reducible_set = &reducible_set_i,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .contains = set_contains,
        .get = set_get,
        .set_item = settable_set_item,
        .set = settable_set_set,
        .remove_item = reducible_remove_item,
        .remove = reducible_set_remove,
};

static void check_as_stream(void **state) {
    assert_ptr_equal(settable_reducible_set_i.as_stream, &stream_i);
}

static void check_as_collection(void **state) {
    assert_ptr_equal(settable_reducible_set_i.as_collection, &collection_i);
}

static void check_as_settable(void **state) {
    assert_ptr_equal(settable_reducible_set_i.as_settable, &settable_i);
}

static void check_as_set(void **state) {
    assert_ptr_equal(settable_reducible_set_i.as_set, &set_i);
}

static void check_as_removable(void **state) {
    assert_ptr_equal(settable_reducible_set_i.as_removable, &removable_i);
}

static void check_as_settable_set(void **state) {
    assert_ptr_equal(settable_reducible_set_i.as_settable_set, &settable_set_i);
}

static void check_as_reducible_set(void **state) {
    assert_ptr_equal(settable_reducible_set_i.as_reducible_set, &reducible_set_i);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.count(NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.count((void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(instance.id->count(&instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.first(NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.first((void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_set_is_empty(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(instance.id->first(&instance, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.last(NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.last((void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(instance.id->last(&instance, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.next(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.next((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.next((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->next(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.prev(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.prev((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.prev((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->prev(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.contains(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_value_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.contains((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.contains((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(set_contains);
    will_return(set_contains,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->contains(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.get(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_value_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.get((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.get((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_value_not_found(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(instance.id->get(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(set_get);
    will_return(set_get,
                BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->get(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_item_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.set_item(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_item_error_on_item_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.set_item((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_set_item_error_on_value_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.set_item((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_set_item_error_on_value_is_invalid(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(instance.id->set_item(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_item_error_on_value_already_exists(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(instance.id->set_item(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_item_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(settable_set_item);
    will_return(settable_set_item,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->set_item(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.set(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_set_error_on_item_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.set((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_set_error_on_value_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.set((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_set_error_on_value_not_found(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(instance.id->set(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_set_error_on_value_is_invalid(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(instance.id->set(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_IS_INVALID);
}

static void check_set_error_on_value_already_exists(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(instance.id->set(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(settable_set_set);
    will_return(settable_set_set,
                BUTTERFLYFISH_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->set(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.remove_item(NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.remove_item((void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_remove_item(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(reducible_remove_item);
    will_return(reducible_remove_item, 0);
    assert_int_equal(instance.id->remove_item(&instance, (void *) 1), 0);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.remove(NULL, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_value_is_null(void **state) {
    assert_int_equal(settable_reducible_set_i.remove((void *) 1, NULL),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_remove_error_on_value_not_found(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(reducible_set_remove);
    will_return(reducible_set_remove,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(instance.id->remove(&instance, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    struct instance instance = {
            .id = &settable_reducible_set_i,
    };
    expect_function_call(reducible_set_remove);
    will_return(reducible_set_remove,
                BUTTERFLYFISH_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(instance.id->remove(&instance, (void *) 1),
                     BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_settable),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_as_removable),
            cmocka_unit_test(check_as_settable_set),
            cmocka_unit_test(check_as_reducible_set),
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
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
            cmocka_unit_test(check_remove_item),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_value_is_null),
            cmocka_unit_test(check_remove_error_on_value_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
