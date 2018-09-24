module Stata

using Serialization, DataFrames

export hello, domath, greet

df = DataFrame()
hello(who::String) = "Hejsan, $who"
domath(x::Number) = x + 5
# greet() = Main.hejsan()
hejsan() = println("Hejsan")
end
