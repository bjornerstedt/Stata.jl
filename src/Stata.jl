module Stata

export hello, domath

hello(who::String) = "Hejsan, $who"
domath(x::Number) = x + 5

end
