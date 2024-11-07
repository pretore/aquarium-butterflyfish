#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

struct object {
    const struct butterflyfish_incremental_list_i *const incremental_list_i;
    const struct butterflyfish_addable_i *const addable_i;
    const struct butterflyfish_list_i *const list_i;
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
list_as_collection(const struct butterflyfish_list_i *const object,
                   const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, list_i, collection_i);
    return 0;
}

static int list_get(const struct butterflyfish_list_i *const object,
                    const uintmax_t at,
                    const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int list_at(const struct butterflyfish_list_i *const object,
                   const struct sea_turtle_integer *const item,
                   uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_list_i list_i = {
        .as_collection = list_as_collection,
        .get = list_get,
        .at = list_at
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
        .add_all = addable_add_all
};

static int
incremental_list_as_list(
        const struct butterflyfish_incremental_list_i *const object,
        const struct butterflyfish_list_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_list_i,
            list_i);
    return 0;
}

static int
incremental_list_as_addable(
        struct butterflyfish_incremental_list_i *const object,
        struct butterflyfish_addable_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, incremental_list_i,
                              addable_i);
    return 0;
}

const struct butterflyfish_incremental_list_i incremental_list_i = {
        .as_addable = incremental_list_as_addable,
        .as_list = incremental_list_as_list,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_i);
    const struct butterflyfish_stream_i *out;
    assert_int_equal(butterflyfish_incremental_list_i_as_stream(
            (const struct butterflyfish_incremental_list_i *) &instance,
                    &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_incremental_list_i_as_collection(
            (const struct butterflyfish_incremental_list_i *) &instance,
                    &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_as_list(NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_as_list((void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_list(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, list_i);
    const struct butterflyfish_list_i *out;
    assert_int_equal(butterflyfish_incremental_list_i_as_list(
            (const struct butterflyfish_incremental_list_i *) &instance,
                    &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_addable_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_as_addable(NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_addable_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_as_addable((void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_as_addable(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, addable_i);
    struct butterflyfish_addable_i *out;
    assert_int_equal(butterflyfish_incremental_list_i_as_addable(
            (struct butterflyfish_incremental_list_i *) &instance,
            &out), 0);
    assert_ptr_equal(out, check);
}

static void check_addable_as_collection(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_i);
    struct butterflyfish_addable_i *as;
    assert_int_equal(butterflyfish_incremental_list_i_as_addable(
            (struct butterflyfish_incremental_list_i *) &instance,
            &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_addable_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_list_as_collection(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    const struct butterflyfish_list_i *as;
    assert_int_equal(butterflyfish_incremental_list_i_as_list(
            (const struct butterflyfish_incremental_list_i *) &instance,
                    &as), 0);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_list_i_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_count((void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_incremental_list_i_count(
            (const struct butterflyfish_incremental_list_i *) &instance,
                    &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_first((void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_list_is_empty(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_incremental_list_i_first(
                    (const struct butterflyfish_incremental_list_i *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_last((void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_list_is_empty(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_incremental_list_i_last(
                    (const struct butterflyfish_incremental_list_i *)
                            &instance,
                    (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_next(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_next(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_next(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_incremental_list_i_next(
                    (const struct butterflyfish_incremental_list_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_prev(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_prev(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_prev(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_incremental_list_i_prev(
                    (const struct butterflyfish_incremental_list_i *)
                            &instance, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_get(NULL, 0, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_get((void *) 1, 0, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_index_out_of_bounds(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(list_get);
    will_return(list_get,
                BUTTERFLYFISH_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_incremental_list_i_get(
                    (const struct butterflyfish_incremental_list_i *)
                            &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_at(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_at((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_at((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL);
}

static void check_at_error_on_item_not_found(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(list_at);
    will_return(list_at,
                BUTTERFLYFISH_LIST_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_incremental_list_i_at(
                    (const struct butterflyfish_incremental_list_i *)
                            &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_ITEM_NOT_FOUND);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_add(NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_add((void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_incremental_list_i_add(
                    (struct butterflyfish_incremental_list_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add);
    will_return(addable_add,
                BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_incremental_list_i_add(
                    (struct butterflyfish_incremental_list_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_incremental_list_i_add_all((void *) 1, NULL),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL);
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .incremental_list_i = &incremental_list_i,
            .addable_i = &addable_i,
            .list_i = &list_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(addable_add_all);
    will_return(addable_add_all,
                BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_incremental_list_i_add_all(
                    (struct butterflyfish_incremental_list_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_list_error_on_object_is_null),
            cmocka_unit_test(check_as_list_error_on_out_is_null),
            cmocka_unit_test(check_as_list),
            cmocka_unit_test(check_as_addable_error_on_object_is_null),
            cmocka_unit_test(check_as_addable_error_on_out_is_null),
            cmocka_unit_test(check_as_addable),
            cmocka_unit_test(check_addable_as_collection),
            cmocka_unit_test(check_list_as_collection),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_list_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_list_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_index_out_of_bounds),
            cmocka_unit_test(check_at_error_on_object_is_null),
            cmocka_unit_test(check_at_error_on_item_is_null),
            cmocka_unit_test(check_at_error_on_out_is_null),
            cmocka_unit_test(check_at_error_on_item_not_found),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_error_on_value_is_invalid),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
