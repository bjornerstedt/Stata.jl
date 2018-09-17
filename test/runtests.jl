using Stata
using Test

@test hello("Julia") == "Hejsan, Julia"
@test domath(2.0) ≈ 7.0
