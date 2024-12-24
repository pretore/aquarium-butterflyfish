#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <seagrass.h>
#include <test/cmocka.h>

struct instance {
    const struct butterflyfish_removable_$t$ *const id;
    void *data;
};

const struct butterflyfish_removable_$t$ removable_$t$;

static int stream_first(const void *const object,
                        const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&removable_$t$ == instance->id);
    return mock();
}

static int stream_next(const void *const object,
                       const $v$const item,
                       const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STREAM_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&removable_$t$ == instance->id);
    return mock();
}

const struct butterflyfish_stream_$t$ stream_$t$ = {
        .first = stream_first,
        .next = stream_next
};

static int
collection_last(const void *const object,
                const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&removable_$t$ == instance->id);
    return mock();
}

static int
collection_prev(const void *const object,
                const $v$const item,
                const $v$*const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&removable_$t$ == instance->id);
    return mock();
}

static int
collection_count(const void *const object, uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&removable_$t$ == instance->id);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_$t$ collection_$t$ = {
        .as_stream = &stream_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
};

static int
reducible_remove_item(void *const object,
                      const $v$const item) {
    if (!object) {
        return BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_REMOVABLE_$T$_ERROR_ITEM_IS_NULL;
    }
    function_called();
    const struct instance *instance = object;
    seagrass_required_true(&removable_$t$ == instance->id);
    return mock();
}

const struct butterflyfish_removable_$t$ removable_$t$ = {
        .as_stream = &stream_$t$,
        .as_collection = &collection_$t$,
        .first = stream_first,
        .next = stream_next,
        .count = collection_count,
        .last = collection_last,
        .prev = collection_prev,
        .remove_item = reducible_remove_item,
};

static void check_as_stream(void **state) {
    assert_ptr_equal(removable_$t$.as_stream, &stream_$t$);
}

static void check_as_collection(void **state) {
    assert_ptr_equal(removable_$t$.as_collection, &collection_$t$);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(removable_$t$.count(NULL, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(removable_$t$.count((void *) 1, NULL),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    struct instance instance = {
            .id = &removable_$t$
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(instance.id->count(&instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(removable_$t$.first(NULL, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(removable_$t$.first((void *) 1, NULL),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_ordered_is_empty(void **state) {
    struct instance instance = {
            .id = &removable_$t$
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(instance.id->first(&instance, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_REMOVABLE_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(removable_$t$.last(NULL, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(removable_$t$.last((void *) 1, NULL),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_ordered_is_empty(void **state) {
    struct instance instance = {
            .id = &removable_$t$
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(instance.id->last(&instance, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_REMOVABLE_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(removable_$t$.next(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(removable_$t$.next((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(removable_$t$.next((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &removable_$t$
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->next(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(removable_$t$.prev(NULL, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(removable_$t$.prev((void *) 1, NULL, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(removable_$t$.prev((void *) 1, (void *) 1, NULL),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    struct instance instance = {
            .id = &removable_$t$
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(instance.id->prev(&instance, (void *) 1, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(removable_$t$.remove_item(NULL, (void *) 1),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(removable_$t$.remove_item((void *) 1, NULL),
                     BUTTERFLYFISH_REMOVABLE_$T$_ERROR_ITEM_IS_NULL);
}

static void check_remove_item(void **state) {
    struct instance instance = {
            .id = &removable_$t$
    };
    expect_function_call(reducible_remove_item);
    will_return(reducible_remove_item, 0);
    assert_int_equal(removable_$t$.remove_item(&instance, (void *) 1), 0);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_ordered_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_ordered_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
            cmocka_unit_test(check_remove_item),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
