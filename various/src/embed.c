#include <julia.h>
#include <stdio.h>
JULIA_DEFINE_FAST_TLS() // only define this once, in an executable (not in a shared library) if you want fast code.


jl_value_t *checked_eval_string(const char* code)
{
    jl_value_t *result = jl_eval_string(code);
    if (jl_exception_occurred()) {
        // none of these allocate, so a gc-root (JL_GC_PUSH) is not necessary
        jl_call2(jl_get_function(jl_base_module, "showerror"),
                 jl_stderr_obj(),
                 jl_exception_occurred());
        jl_printf(jl_stderr_stream(), "\n");
        jl_atexit_hook(1);
        exit(1);
    }
    assert(result && "Missing return value but no exception occurred!");
    return result;
}

int main(int argc, char *argv[])
{
    /* required: setup the Julia context */
    jl_init();

    /* run Julia commands */

    // checked_eval_string("using Stata");
    // checked_eval_string("Stata.hello(\"Stupid\")");
    checked_eval_string("Base.MainInclude.include(\"test.jl\")");
    // checked_eval_string("run(`ls`)" );
    // checked_eval_string("include(\"test.jl\")");
    checked_eval_string("Main.hejsan()");
    jl_atexit_hook(0);

    return 0;
}
