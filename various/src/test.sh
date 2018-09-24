$JULIA_HOME/share/julia/julia-config.jl --cflags --ldflags --ldlibs | xargs gcc embed.c

./a.out
