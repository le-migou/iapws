#pragma once
#include "detail/common.hpp"

    namespace 
calculisto::iapws::r6
{
    inline namespace 
r6_95_2016
{
    namespace 
detail // {{{
{
    using std::pow;

    // Table 6.1.
    constexpr double
n_0_1 = -8.3204464837497;
    constexpr double
n_0_2 =  6.6832105275932;
    constexpr double
n_0_3 =  3.00632;          
    constexpr array_t
n_0 {
      0.012436         
    , 0.97315          
    , 1.27950          
    , 0.96956          
    , 0.24873          
};
    constexpr array_t
gamma_0 {
      1.28728967  
    , 3.53734222
    , 7.74073708
    , 9.24437796
    , 27.5075105
};
    // Table 6.2.
    constexpr array_t
c_2
{
      1.0     // 8   
    , 1.0     // 9   
    , 1.0     // 10  
    , 1.0     // 11  
    , 1.0     // 12  
    , 1.0     // 13  
    , 1.0     // 14  
    , 1.0     // 15  
    , 1.0     // 16  
    , 1.0     // 17  
    , 1.0     // 18  
    , 1.0     // 19  
    , 1.0     // 20  
    , 1.0     // 21  
    , 1.0     // 22  
    , 2.0     // 23  
    , 2.0     // 24  
    , 2.0     // 25  
    , 2.0     // 26  
    , 2.0     // 27  
    , 2.0     // 28  
    , 2.0     // 29  
    , 2.0     // 30  
    , 2.0     // 31  
    , 2.0     // 32  
    , 2.0     // 33  
    , 2.0     // 34  
    , 2.0     // 35  
    , 2.0     // 36  
    , 2.0     // 37  
    , 2.0     // 38  
    , 2.0     // 39  
    , 2.0     // 40  
    , 2.0     // 41  
    , 2.0     // 42  
    , 3.0     // 43  
    , 3.0     // 44  
    , 3.0     // 45  
    , 3.0     // 46  
    , 4.0     // 47  
    , 6.0     // 48  
    , 6.0     // 49  
    , 6.0     // 50  
    , 6.0     // 51  
};
    constexpr array_t
d_1
{
      1.0    // 1   
    , 1.0    // 2   
    , 1.0    // 3   
    , 2.0    // 4   
    , 2.0    // 5   
    , 3.0    // 6   
    , 4.0    // 7   
};
    constexpr array_t
d_2
{
       1.0   // 8   
    ,  1.0   // 9   
    ,  1.0   // 10  
    ,  2.0   // 11  
    ,  2.0   // 12  
    ,  3.0   // 13  
    ,  4.0   // 14  
    ,  4.0   // 15  
    ,  5.0   // 16  
    ,  7.0   // 17  
    ,  9.0   // 18  
    , 10.0   // 19  
    , 11.0   // 20  
    , 13.0   // 21  
    , 15.0   // 22  
    ,  1.0   // 23  
    ,  2.0   // 24  
    ,  2.0   // 25  
    ,  2.0   // 26  
    ,  3.0   // 27  
    ,  4.0   // 28  
    ,  4.0   // 29  
    ,  4.0   // 30  
    ,  5.0   // 31  
    ,  6.0   // 32  
    ,  6.0   // 33  
    ,  7.0   // 34  
    ,  9.0   // 35  
    ,  9.0   // 36  
    ,  9.0   // 37  
    ,  9.0   // 38  
    ,  9.0   // 39  
    , 10.0   // 40  
    , 10.0   // 41  
    , 12.0   // 42  
    ,  3.0   // 43  
    ,  4.0   // 44  
    ,  4.0   // 45  
    ,  5.0   // 46  
    , 14.0   // 47  
    ,  3.0   // 48  
    ,  6.0   // 49  
    ,  6.0   // 50  
    ,  6.0   // 51  
};
    constexpr array_t
d_3
{
      3.0    // 52  
    , 3.0    // 53  
    , 3.0    // 54  
};
    constexpr array_t
t_1
{
      -0.5      // 1   
    ,  0.875    // 2   
    ,  1.0      // 3   
    ,  0.5      // 4   
    ,  0.75     // 5   
    ,  0.375    // 6   
    ,  1.0      // 7   
};
    constexpr array_t
t_2
{
       4.0      // 8
    ,  6.0      // 9
    , 12.0      // 10
    ,  1.0      // 11
    ,  5.0      // 12
    ,  4.0      // 13
    ,  2.0      // 14
    , 13.0      // 15
    ,  9.0      // 16
    ,  3.0      // 17
    ,  4.0      // 18
    , 11.0      // 19
    ,  4.0      // 20
    , 13.0      // 21
    ,  1.0      // 22
    ,  7.0      // 23
    ,  1.0      // 24
    ,  9.0      // 25
    , 10.0      // 26
    , 10.0      // 27
    ,  3.0      // 28
    ,  7.0      // 29
    , 10.0      // 30
    , 10.0      // 31
    ,  6.0      // 32
    , 10.0      // 33
    , 10.0      // 34
    ,  1.0      // 35
    ,  2.0      // 36
    ,  3.0      // 37
    ,  4.0      // 38
    ,  8.0      // 39
    ,  6.0      // 40
    ,  9.0      // 41
    ,  8.0      // 42
    , 16.0      // 43
    , 22.0      // 44
    , 23.0      // 45
    , 23.0      // 46
    , 10.0      // 47
    , 50.0      // 48
    , 44.0      // 49
    , 46.0      // 50
    , 50.0      // 51
};
    constexpr array_t
t_3
{
      0.0        // 52  
    , 1.0        // 53  
    , 4.0        // 54  
};
    constexpr array_t
n_1
{
       0.12533547935523e-1  // 1   
    ,  0.78957634722828e1   // 2   
    , -0.87803203303561e1   // 3   
    ,  0.31802509345418     // 4   
    , -0.26145533859358     // 5   
    , -0.78199751687981e-2  // 6   
    ,  0.88089493102134e-2  // 7   
};
    constexpr array_t
n_2
{
      -0.66856572307965     // 8   
    ,  0.20433810950965     // 9   
    , -0.66212605039687e-4  // 10  
    , -0.19232721156002     // 11  
    , -0.25709043003438     // 12  
    ,  0.16074868486251     // 13  
    , -0.40092828925807e-1  // 14  
    ,  0.39343422603254e-6  // 15  
    , -0.75941377088144e-5  // 16  
    ,  0.56250979351888e-3  // 17  
    , -0.15608652257135e-4  // 18  
    ,  0.11537996422951e-8  // 19  
    ,  0.36582165144204e-6  // 20  
    , -0.13251180074668e-11 // 21  
    , -0.62639586912454e-9  // 22  
    , -0.10793600908932     // 23  
    ,  0.17611491008752e-1  // 24  
    ,  0.22132295167546     // 25  
    , -0.40247669763528     // 26  
    ,  0.58083399985759     // 27  
    ,  0.49969146990806e-2  // 28  
    , -0.31358700712549e-1  // 29  
    , -0.74315929710341     // 30  
    ,  0.47807329915480     // 31  
    ,  0.20527940895948e-1  // 32  
    , -0.13636435110343     // 33  
    ,  0.14180634400617e-1  // 34  
    ,  0.83326504880713e-2  // 35  
    , -0.29052336009585e-1  // 36  
    ,  0.38615085574206e-1  // 37  
    , -0.20393486513704e-1  // 38  
    , -0.16554050063734e-2  // 39  
    ,  0.19955571979541e-2  // 40  
    ,  0.15870308324157e-3  // 41  
    , -0.16388568342530e-4  // 42  
    ,  0.43613615723811e-1  // 43  
    ,  0.34994005463765e-1  // 44  
    , -0.76788197844621e-1  // 45  
    ,  0.22446277332006e-1  // 46  
    , -0.62689710414685e-4  // 47  
    , -0.55711118565645e-9  // 48  
    , -0.19905718354408     // 49  
    ,  0.31777497330738     // 50  
    , -0.11841182425981     // 51  
};
    constexpr array_t
n_3
{
      -0.31306260323435e2   // 52  
    ,  0.31546140237781e2   // 53  
    , -0.25213154341695e4   // 54  
};
    constexpr array_t
n_4
{
      -0.14874640856724     // 55  
    ,  0.31806110878444     // 56  
};

    constexpr array_t
alpha
{
      20.0
    , 20.0
    , 20.0
};
    constexpr array_t
beta_1
{
      150.0
    , 150.0
    , 250.0
};
    constexpr array_t
gamma
{
      1.21
    , 1.21
    , 1.25
};
    constexpr array_t
epsilon
{
      1.0
    , 1.0
    , 1.0
};

    constexpr array_t
beta_2
{
      0.3
    , 0.3
};
    constexpr array_t
a
{
      3.5
    , 3.5
};
    constexpr array_t
b
{
      0.85
    , 0.95
};
    constexpr array_t
B
{
      0.2
    , 0.2
};
    constexpr array_t
C
{
      28.0
    , 32.0
};
    constexpr array_t
D
{
      700.0
    , 800.0
};
    constexpr array_t
A
{
      0.32
    , 0.32
};


    constexpr auto
phi_0 (auto const& delta, auto const& tau)
{
        using std::log;
    return 
          log (delta) + n_0_1 + n_0_2 * tau + n_0_3 * log (tau)
        + sum (n_0 * log (1. - exp (-gamma_0 * tau)))
    ;
}
    constexpr auto
phi_0_d (auto const& delta, auto const& /*tau*/)
{
    return 1. / delta;
}
    constexpr auto
phi_0_dd (auto const& delta, auto const& /*tau*/)
{
    return -1. / delta / delta;
}
    constexpr auto
phi_0_t (auto const& /*delta*/, auto const& tau)
{
    return 
          n_0_2 + n_0_3 / tau
        + sum (n_0 * gamma_0 * (pow (1. - exp (-gamma_0 * tau), -1.) - 1.))
    ;
}
    constexpr auto
phi_0_tt (auto const& /*delta*/, auto const& tau)
{
    return 
        - n_0_3 / tau / tau
        - sum (n_0 * gamma_0 * gamma_0 * exp (-gamma_0 * tau) 
            * pow (1. - exp (-gamma_0 * tau), -2.))
    ;
}
    constexpr auto
Theta (auto const& delta, auto const& tau)
{
    return (1. - tau) + A * pow (pow (delta - 1., 2.), 1. / (2. * beta_2));
}
    constexpr auto
Delta (auto const& delta, auto const& tau)
{
    return 
          pow (Theta (delta, tau), 2.)
        + B * pow (pow (delta - 1., 2.), a);
    ;
}
    constexpr auto
Psi (auto const& delta, auto const& tau)
{
    return exp (-C * pow (delta - 1, 2.) - D * pow (tau - 1, 2.));
}
    constexpr auto
phi_r (auto const& delta, auto const& tau)
{
    return
          sum (n_1 * pow (delta, d_1) * pow (tau, t_1))
        + sum (n_2 * pow (delta, d_2) * pow (tau, t_2) * exp (-pow (delta, c_2)))
        + sum (n_3 * pow (delta, d_3) * pow (tau, t_3) * exp (
                - alpha * pow (delta - epsilon, 2.0) 
                - beta_1 * pow (tau - gamma, 2.0)
          ))
        + sum (n_4 * pow (Delta (delta, tau), b) * delta * Psi (delta, tau))
    ;
}

    constexpr auto
Delta_d (auto const& delta, auto const& tau)
{
    return (delta - 1.) * (
          A * Theta (delta, tau) * 2 / beta_2 
        * pow (pow (delta - 1, 2.), (0.5 / beta_2 - 1)) 
        + 2 * B * a * pow (pow (delta - 1, 2.), (a - 1))
    );

}
    constexpr auto
Delta_dd (auto /*const&*/ delta, auto const& tau)
{
    // TODO: there's probably a way to rewrite this math
    // without a singularity.

    // Here we get rid of the singularity shown below.
    // Ideally we should use std::nextafter but it will not generalize easily
    // (e.g. what if auto has an uncertainty?).
    if (delta == 1) delta += std::numeric_limits <double>::epsilon ();
    // Here be the singularity (when delta = 1)!
    //        |
    //        v
    return
          1 / (delta - 1) * Delta_d (delta, tau) 
    //    ~~~~~~~~~~~~~~~
        + pow (delta - 1, 2) * ( 4 * B * a * (a - 1) 
            * pow (pow (delta - 1, 2), a - 2) 
        + 2 * pow (A, 2) * pow (beta_2, -2) 
            * pow ( pow (pow (delta - 1, 2), 0.5 / beta_2 - 1) , 2) 
        + A * Theta (delta, tau) * 4 / beta_2 * (0.5 / beta_2 - 1) 
            * pow (pow (delta - 1, 2), 0.5 / beta_2 - 2)
    );
}
/* This wil NaN for delta < 1 (i.e. density below the critical density). */
    constexpr auto
Delta_ddd (auto const& delta, auto const& tau)
{
    return 
          2 * Theta (delta, tau) * A / beta_2 * (1 / beta_2 - 1) 
            * (1 / beta_2 - 2) * pow (delta - 1, 1 / beta_2 - 3)
    //                           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        + 6 * pow (A, 2) / pow (beta_2, 2) * (1 / beta_2 - 1) * pow (delta - 1, 2 / beta_2 - 3)
    //                                                          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        + 2 * B * a * (2 * a - 1) * (2 * a - 2) * pow (delta - 1, 2 * a - 3)
    //                                            ~~~~~~~~~~~~~~~~~~~~~~~~~~
    ;
}
    constexpr auto
Delta_b_d (auto const& delta, auto const& tau)
{
    return b * pow (Delta (delta, tau), b - 1.) * Delta_d (delta, tau);
}
    constexpr auto
Delta_b_dd (auto const& delta, auto const& tau)
{
    return b * (
          pow (Delta (delta, tau), b -1) * Delta_dd (delta, tau) 
        + (b - 1) * pow (Delta(delta, tau), b - 2) 
            * pow (Delta_d (delta, tau), 2)
    );
}
    constexpr auto
Delta_b_ddd (auto const& delta, auto const& tau)
{
    return b * pow (Delta (delta, tau), b - 3) * (
          pow (Delta (delta, tau), 2) * Delta_ddd (delta, tau) 
        + 3 * (b - 1) * Delta (delta, tau) * Delta_d (delta, tau) * Delta_dd (delta, tau)
        + (b - 1) * (b - 2) * pow (Delta_d (delta, tau), 3)
    );
}
    constexpr auto
Psi_d (auto const& delta, auto const& tau)
{
    return -2 * C * (delta - 1) * Psi (delta, tau);
}
    constexpr auto
Psi_dd (auto const& delta, auto const& tau)
{
    return 2 * C * Psi (delta, tau) * (2 * C * pow (delta - 1, 2) - 1);
}
    constexpr auto
Psi_ddd (auto const& delta, auto const& tau)
{
    return 4 * (delta - 1) * (3 - 2 * pow (delta - 1, 2) * C) * 
        C * C * Psi (delta, tau);
}
    constexpr auto
phi_r_d (auto const& delta, auto const& tau)
{
    return
          sum (n_1 * d_1 * pow (delta, d_1 - 1.) * pow (tau, t_1))
        + sum (n_2 * exp (-pow (delta, c_2)) * (pow (delta, d_2 - 1.) 
            * pow (tau, t_2) * (d_2 - c_2 * pow (delta, c_2))))
        + sum (n_3 * pow (delta, d_3) * pow (tau, t_3) * exp (
                - alpha * pow (delta - epsilon, 2) 
                - beta_1 * pow (tau - gamma, 2)
          ) * (d_3 / delta - 2. * alpha * (delta - epsilon)))
        + sum (n_4 * (
              pow (Delta (delta, tau), b) * (
                  Psi (delta, tau) + delta * Psi_d (delta, tau)
              )
            + Delta_b_d (delta, tau) * delta * Psi (delta, tau)
          ))
    ;
}
    constexpr auto
phi_r_dd (auto const& delta, auto const& tau)
{
    return
          sum (n_1 * d_1 * (d_1 - 1) * pow (delta, d_1 - 2) * pow (tau, t_1))
        + sum (
              n_2 * exp (-pow (delta, c_2)) * (
              pow (delta, d_2 - 2) * pow (tau, t_2) * (
                  (d_2 - c_2 * pow (delta, c_2)) 
                * (d_2 - 1 - c_2 * pow (delta, c_2))
                - pow (c_2, 2) * pow (delta, c_2)
              ))
          )
        + sum (
              n_3 * pow (tau, t_3) 
            * exp(
                  -alpha * pow (delta - epsilon, 2) 
                - beta_1 * pow (tau - gamma, 2)
              ) * (
                  -2 * alpha * pow (delta, d_3) 
                + 4 * pow (alpha, 2) * pow (delta, d_3) 
                    * pow (delta - epsilon, 2) 
                - 4 * d_3 * alpha * pow (delta, d_3 - 1) * (delta - epsilon) 
                + d_3 * (d_3 - 1) * pow (delta, d_3 - 2)
              )
          )
        + sum (
              n_4 * (pow (Delta(delta, tau), b) * (
                  2 * Psi_d (delta, tau) 
                + delta * Psi_dd (delta, tau)
              ) 
            + 2 * Delta_b_d (delta, tau) * (
                  Psi (delta, tau) 
                + delta * Psi_d (delta, tau)
              ) 
            + Delta_b_dd (delta, tau) * delta * Psi (delta, tau))
          )
    ;
}
/* This was for debugging, I don't feel confortable deleting it yet.
    constexpr auto
s1_dd (auto const& delta, auto const& tau)
{
    return
          sum (n_1 * d_1 * (d_1 - 1) * pow (delta, d_1 - 2) * pow (tau, t_1))
    ;
}
    constexpr auto
s2_dd (auto const& delta, auto const& tau)
{
    return
          sum (
              n_2 * exp (-pow (delta, c_2)) * (
              pow (delta, d_2 - 2) * pow (tau, t_2) * (
                  (d_2 - c_2 * pow (delta, c_2)) 
                * (d_2 - 1 - c_2 * pow (delta, c_2))
                - pow (c_2, 2) * pow (delta, c_2)
              ))
          )
    ;
}
    constexpr auto
s3_dd (auto const& delta, auto const& tau)
{
    return
          sum (
              n_3 * pow (tau, t_3) 
            * exp(
                  -alpha * pow (delta - epsilon, 2) 
                - beta_1 * pow (tau - gamma, 2)
              ) * (
                  -2 * alpha * pow (delta, d_3) 
                + 4 * pow (alpha, 2) * pow (delta, d_3) 
                    * pow (delta - epsilon, 2) 
                - 4 * d_3 * alpha * pow (delta, d_3 - 1) * (delta - epsilon) 
                + d_3 * (d_3 - 1) * pow (delta, d_3 - 2)
              )
          )
    ;
}
    constexpr auto
s4_dd (auto const& delta, auto const& tau)
{
    return
          sum (
              n_4 * (pow (Delta(delta, tau), b) * (
                  2 * Psi_d (delta, tau) 
                + delta * Psi_dd (delta, tau)
              ) 
            + 2 * Delta_b_d (delta, tau) * (
                  Psi (delta, tau) 
                + delta * Psi_d (delta, tau)
              ) 
            + Delta_b_dd (delta, tau) * delta * Psi (delta, tau))
          )
    ;
}
*/
/* This wil NaN for delta < 1 (i.e. density below the critical density). */
    constexpr auto
phi_r_ddd (auto const& delta, auto const& tau)
{
    return
          sum (
              n_1 * d_1 * (d_1 - 1) * (d_1 - 2) 
            * pow (delta, d_1 - 3) * pow (tau, t_1)
          )
        + sum (
              n_2 * exp (-pow (delta, c_2)) 
            * pow (tau, t_2) * pow (delta, d_2 - 3) 
            * (
                  d_2 * (d_2 * d_2 - 3 * d_2 + 2)
                + (3 * d_2 * (2 - d_2 - c_2) 
                    - c_2 * c_2 + 3 * c_2 - 2
                  ) * c_2 * pow (delta, c_2)
                + 3 * (d_2 + c_2 - 1) * c_2 * c_2 * pow (delta, 2 * c_2)
                - pow (c_2, 3) * pow (delta, 3 * c_2)
              )
          )
        + sum (
              n_3 * pow (tau, t_3)
            * exp(
                  -alpha * pow (delta - epsilon, 2) 
                - beta_1 * pow (tau - gamma, 2)
              ) * (
                  - 8 * pow (alpha, 3) * pow (delta, d_3) * pow (delta - epsilon, 3)
                  + 12 * pow (alpha, 2) * d_3 * pow (delta, d_3 - 1) * pow (delta - epsilon, 2)
                  + 12 * pow (alpha, 2) * pow (delta, d_3) * (delta - epsilon)
                  - 6 * alpha * d_3 * (d_3 - 1) * pow (delta, d_3 - 2) * (delta - epsilon)
                  - 6 * alpha * d_3 * pow (delta, d_3 - 1)
                  + d_3 * (d_3 - 1) * (d_3 - 2) * pow (delta, d_3 - 3)
              )
          )
        + sum (n_4 * (
              pow (Delta (delta, tau), b) * (3 * Psi_dd (delta, tau) + delta * Psi_ddd (delta, tau))
            + 3 * Delta_b_d (delta, tau) * (2 * Psi_d (delta, tau) + delta * Psi_dd (delta, tau))
            + 3 * Delta_b_dd (delta, tau) * (Psi (delta, tau) + delta * Psi_d (delta, tau))
            +     Delta_b_ddd (delta, tau) * delta * Psi (delta, tau)
          ))
    ;
}
/*
    constexpr auto
s1_ddd (auto const& delta, auto const& tau)
{
    return
          sum (
              n_1 * d_1 * (d_1 - 1) * (d_1 - 2) 
            * pow (delta, d_1 - 3) * pow (tau, t_1)
          )
    ;
}
    constexpr auto
s2_ddd (auto const& delta, auto const& tau)
{
    return
          sum (
              n_2 * exp (-pow (delta, c_2)) 
            * pow (tau, t_2) * pow (delta, d_2 - 3) 
            * (
                  d_2 * (d_2 * d_2 - 3 * d_2 + 2)
                + (3 * d_2 * (2 - d_2 - c_2) 
                    - c_2 * c_2 + 3 * c_2 - 2
                  ) * c_2 * pow (delta, c_2)
                + 3 * (d_2 + c_2 - 1) * c_2 * c_2 * pow (delta, 2 * c_2)
                - pow (c_2, 3) * pow (delta, 3 * c_2)
              )
          )
    ;
}
    constexpr auto
s3_ddd (auto const& delta, auto const& tau)
{
    return
          sum (
              n_3 * pow (tau, t_3)
            * exp(
                  -alpha * pow (delta - epsilon, 2) 
                - beta_1 * pow (tau - gamma, 2)
              ) * (
                  - 8 * pow (alpha, 3) * pow (delta, d_3) * pow (delta - epsilon, 3)
                  + 12 * pow (alpha, 2) * d_3 * pow (delta, d_3 - 1) * pow (delta - epsilon, 2)
                  + 12 * pow (alpha, 2) * pow (delta, d_3) * (delta - epsilon)
                  - 6 * alpha * d_3 * (d_3 - 1) * pow (delta, d_3 - 2) * (delta - epsilon)
                  - 6 * alpha * d_3 * pow (delta, d_3 - 1)
                  + d_3 * (d_3 - 1) * (d_3 - 2) * pow (delta, d_3 - 3)
              )
          )
    ;
}
    constexpr auto
s4_ddd (auto const& delta, auto const& tau)
{
    return
          sum (n_4 * (
              pow (Delta (delta, tau), b) * (3 * Psi_dd (delta, tau) + delta * Psi_ddd (delta, tau))
            + 3 * Delta_b_d (delta, tau) * (2 * Psi_d (delta, tau) + delta * Psi_dd (delta, tau))
            + 3 * Delta_b_dd (delta, tau) * (Psi (delta, tau) + delta * Psi_d (delta, tau))
            +     Delta_b_ddd (delta, tau) * delta * Psi (delta, tau)
          ))
    ;
}
*/
    constexpr auto
Delta_b_t (auto const& delta, auto const& tau)
{
    return -2. * Theta (delta, tau) * b * pow (Delta (delta, tau), b - 1.);
}
    constexpr auto
Delta_b_tt (auto const& delta, auto const& tau)
{
    return 
          2. * b * pow (Delta (delta, tau), b - 1.)
        + 4. * pow (Theta (delta, tau), 2.) * b * (b - 1.) 
            * pow (Delta (delta, tau), b - 2.)
    ;
}
    constexpr auto
Psi_t (auto const& delta, auto const& tau)
{
    return -2 * D * (tau - 1) * Psi (delta, tau);
}
    constexpr auto
Psi_tt (auto const& delta, auto const& tau)
{
    return 2 * D * Psi (delta, tau) * (2 * D * pow (tau - 1, 2) - 1);
}

    constexpr auto
phi_r_t (auto const& delta, auto const& tau)
{
    return
          sum (n_1 * t_1 * pow (delta, d_1) * pow (tau, t_1 - 1))
        + sum (n_2 * t_2 * pow (delta, d_2) * pow (tau, t_2 - 1) 
            * exp (-pow (delta, c_2)))
        + sum (n_3 * pow (delta, d_3) * pow (tau, t_3) 
            * exp (
                - alpha * pow (delta - epsilon, 2.) 
                - beta_1 * pow (tau - gamma, 2.)
              )
            * (t_3 / tau - 2. * beta_1 * (tau - gamma))
          )
        + sum (n_4 * delta * (Delta_b_t (delta, tau) * Psi (delta, tau) 
            + pow (Delta (delta, tau), b) * Psi_t (delta, tau))
          )
    ;
}
    constexpr auto
phi_r_tt (auto const& delta, auto const& tau)
{
    return
          sum (n_1 * t_1 * (t_1 - 1.) * pow (delta, d_1) * pow (tau, t_1 - 2))
        + sum (n_2 * t_2 * (t_2 - 1.) * pow (delta, d_2) * pow (tau, t_2 - 2) 
                * exp (-pow (delta, c_2))
          )
        + sum (n_3 * pow (delta, d_3) * pow (tau, t_3) 
            * exp (-alpha * pow (delta - epsilon, 2) 
                - beta_1 * pow (tau - gamma, 2))
            * (pow (t_3 / tau - 2 * beta_1 * (tau - gamma), 2) 
                - t_3 / tau / tau - 2 * beta_1)
          )
        + sum (n_4 * delta * (
              Delta_b_tt (delta, tau) * Psi (delta, tau) 
            + 2 * Delta_b_t (delta, tau) * Psi_t (delta, tau) 
            + pow (Delta (delta, tau), b) * Psi_tt (delta, tau)
          ))
    ;
}

    constexpr auto
Delta_b_dt (auto const& delta, auto const& tau)
{
    return 
          -A * b * 2 / beta_2 * pow (Delta (delta, tau), b - 1) * (delta - 1.) 
            * pow (pow (delta - 1., 2), 1. / 2. / beta_2 - 1.)
        - 2 * Theta (delta, tau) * b * (b - 1) * pow (Delta (delta, tau), b - 2) 
            * Delta_d (delta, tau)
    ;
}
    constexpr auto
Psi_dt (auto const& delta, auto const& tau)
{
    return 4 * C * D * (delta - 1) * (tau - 1) * Psi (delta, tau);
}

    constexpr auto
phi_r_dt (auto const& delta, auto const& tau)
{
    return
          sum (n_1 * d_1 * t_1 * pow (delta, d_1 - 1) * pow (tau, t_1 - 1))
        + sum (n_2 * t_2 * pow (delta, d_2 - 1) * pow (tau, t_2 - 1) 
            * (d_2 - c_2 * pow (delta, c_2)) * exp (-pow (delta, c_2))
          )
        + sum (n_3 * pow (delta, d_3) * pow (tau, t_3) 
            * exp (-alpha * pow (delta - epsilon, 2) 
                - beta_1 * pow (tau - gamma, 2)
              ) 
            * (d_3 / delta - 2 * alpha * (delta - epsilon))
            * (t_3 / tau - 2 * beta_1 * (tau - gamma))
          )
        + sum (n_4 * (
              pow (Delta (delta, tau), b) 
                * (Psi_t (delta, tau) + delta * Psi_dt (delta, tau))
            + delta * Delta_b_d (delta, tau) * Psi_t (delta, tau)
            + Delta_b_t (delta, tau) * (Psi (delta, tau) + delta 
                * Psi_d (delta, tau))
            + Delta_b_dt (delta, tau) * delta * Psi (delta, tau)
          ))
    ;
}

} // }}} namespace detail
    constexpr auto
massic_gas_constant = 0.46151805e3;

    constexpr auto
critical_temperature = 647.096;

    constexpr auto
critical_pressure = 22.064e6;

    constexpr auto
critical_density = 322.0;

    constexpr auto
triple_point_temperature = 273.16;

    constexpr auto
triple_point_pressure = 611.657;

#define ISTO_IAPWS_R6_GENERATE_FUNCTIONS(NAME, FORMULA)  \
    constexpr auto                                       \
NAME##_dt (auto const& density, auto const& temperature) \
{                                                        \
        auto                                             \
    delta = density / critical_density;                  \
        auto                                             \
    tau = critical_temperature / temperature;            \
    return FORMULA;                                      \
}                                                        \
    constexpr auto                                       \
NAME##_td (auto const& temperature, auto const& density) \
{                                                        \
    return NAME##_dt (density, temperature);             \
}
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(pressure, (1. + delta * detail::phi_r_d (delta, tau)) * density * massic_gas_constant * temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_internal_energy, (tau * (detail::phi_0_t (delta, tau) + detail::phi_r_t (delta, tau))) * massic_gas_constant * temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_entropy, (tau * (detail::phi_0_t (delta, tau) + detail::phi_r_t (delta, tau)) - detail::phi_0 (delta, tau) - detail::phi_r (delta, tau)) * massic_gas_constant)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_enthalpy, (1. + tau * (detail::phi_0_t (delta, tau) + detail::phi_r_t (delta, tau)) + delta * detail::phi_r_d (delta, tau)) * massic_gas_constant * temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_isochoric_heat_capacity, (-tau * tau * (detail::phi_0_tt (delta, tau) + detail::phi_r_tt (delta, tau))) * massic_gas_constant)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_isobaric_heat_capacity,  (-tau * tau * (detail::phi_0_tt (delta, tau) + detail::phi_r_tt (delta, tau)) + pow (1. + delta * detail::phi_r_d (delta, tau) - delta * detail::phi_r_dt (delta, tau), 2) / (1. + 2. * delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau))) * massic_gas_constant)
//ISTO_IAPWS_R6_GENERATE_FUNCTIONS(joule_thompson_coefficient, (- (delta * phi_r_d (delta, tau) + delta * delta * phi_r_dd (delta, tau) + delta * tau * phi_r_dt (delta, tau)) / (pow (1. + delta * phi_r_d (delta, tau) - delta * tau * phi_r_dt (delta, tau), 2.) - tau * tau * (phi_0_tt (delta, tau) + phi_r_tt (delta, tau)) * (1. + 2. * delta * phi_r_d (delta, tau) + delta * delta * phi_r_dd (delta, tau)))) / density / massic_gas_constant)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_gibbs_free_energy, (1. + detail::phi_0 (delta, tau) + detail::phi_r (delta, tau) + delta * detail::phi_r_d (delta, tau)) * massic_gas_constant * temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(speed_of_sound, (pow ((1 + 2. * delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau) - pow (1. + delta * detail::phi_r_d (delta, tau) - delta * tau * detail::phi_r_dt (delta, tau), 2) / (tau * tau * (detail::phi_0_tt (delta, tau) + detail::phi_r_tt (delta, tau)))) * massic_gas_constant * temperature, 0.5)))
// AN3, no tests for these
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(isothermal_stress_coefficient, (1. + ((delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau)) / (1. + delta * detail::phi_r_d (delta, tau)))) * density)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(relative_pressure_coefficient, (1. - ((delta * tau * detail::phi_r_dt (delta, tau)) / (1. + delta * detail::phi_r_d (delta, tau)))) / temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(isobaric_cubic_expansion_coefficient, ((1. + delta * detail::phi_r_d (delta, tau) - delta * tau * detail::phi_r_dt (delta, tau)) / (1. + 2 * delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau))) / temperature)
//ISTO_IAPWS_R6_GENERATE_FUNCTIONS(isothermal_compressibility, (1. / (1. + 2. * delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau))) / density / massic_gas_constant / temperature)
#undef ISTO_IAPWS_R6_GENERATE_FUNCTIONS

} // inline namespace r6_95_2016
} // namespace calculisto::iapws::r6

    namespace
calculisto::iapws::r6_gas
{
    inline namespace 
r6_95_2016
{
    namespace
detail // {{{
{
    constexpr auto
n = array_t
{
       0.4748659259
    , -0.1124370553e1
    , -0.8118627401
    , -0.6213018501e-3
    ,  0.1924430993
    , -0.8322867662e-1
    ,  0.1391052230e1
};
    constexpr auto
d = array_t
{
      1.
    , 1.
    , 1.
    , 1.
    , 2.
    , 2.
    , 4.
};
    constexpr auto
t = array_t
{
       0.25
    ,  1.25
    ,  3.5 
    , 12.  
    ,  1.5 
    , 13.5 
    ,  8.75
};
    constexpr auto
phi_r (auto const& delta, auto const& tau)
{
    return sum (n * pow (delta, d) * pow (tau, t));
}
    constexpr auto
phi_r_d (auto const& delta, auto const& tau)
{
    return sum (n * d * pow (delta, d - 1.) * pow (tau, t));
}
    constexpr auto
phi_r_dd (auto const& delta, auto const& tau)
{
    return sum (n * d * (d - 1) * pow (delta, d - 2) * pow (tau, t));
}
    constexpr auto
phi_r_ddd (auto const& delta, auto const& tau)
{
    return sum (
          n * d * (d - 1) * (d - 2) 
        * pow (delta, d - 3) * pow (tau, t)
    );
}
    constexpr auto
phi_r_t (auto const& delta, auto const& tau)
{
    return sum (n * t * pow (delta, d) * pow (tau, t - 1));
}
    constexpr auto
phi_r_tt (auto const& delta, auto const& tau)
{
    return sum (n * t * (t - 1.) * pow (delta, d) * pow (tau, t - 2));
}
    constexpr auto
phi_r_dt (auto const& delta, auto const& tau)
{
    return sum (n * d * t * pow (delta, d - 1) * pow (tau, t - 1));
}
} // namespace detail }}}
    constexpr auto
massic_gas_constant = 0.46151805e3;

    constexpr auto
critical_temperature = 647.096;

    constexpr auto
critical_pressure = 22.064e6;

    constexpr auto
critical_density = 322.0;

    constexpr auto
triple_point_temperature = 273.16;

    constexpr auto
triple_point_pressure = 611.657;

#define ISTO_IAPWS_R6_GENERATE_FUNCTIONS(NAME, FORMULA)  \
    constexpr auto                                       \
NAME##_dt (auto const& density, auto const& temperature) \
{                                                        \
        auto                                             \
    delta = density / critical_density;                  \
        auto                                             \
    tau = critical_temperature / temperature;            \
    return FORMULA;                                      \
}                                                        \
    constexpr auto                                       \
NAME##_td (auto const& temperature, auto const& density) \
{                                                        \
    return NAME##_dt (density, temperature);             \
}
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(pressure, (1. + delta * detail::phi_r_d (delta, tau)) * density * massic_gas_constant * temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_internal_energy, (tau * (r6::detail::phi_0_t (delta, tau) + detail::phi_r_t (delta, tau))) * massic_gas_constant * temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_entropy, (tau * (r6::detail::phi_0_t (delta, tau) + detail::phi_r_t (delta, tau)) - r6::detail::phi_0 (delta, tau) - detail::phi_r (delta, tau)) * massic_gas_constant)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_enthalpy, (1. + tau * (r6::detail::phi_0_t (delta, tau) + detail::phi_r_t (delta, tau)) + delta * detail::phi_r_d (delta, tau)) * massic_gas_constant * temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_isochoric_heat_capacity, (-tau * tau * (r6::detail::phi_0_tt (delta, tau) + detail::phi_r_tt (delta, tau))) * massic_gas_constant)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_isobaric_heat_capacity,  (-tau * tau * (r6::detail::phi_0_tt (delta, tau) + detail::phi_r_tt (delta, tau)) + pow (1. + delta * detail::phi_r_d (delta, tau) - delta * detail::phi_r_dt (delta, tau), 2) / (1. + 2. * delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau))) * massic_gas_constant)
//ISTO_IAPWS_R6_GENERATE_FUNCTIONS(joule_thompson_coefficient, (- (delta * phi_r_d (delta, tau) + delta * delta * phi_r_dd (delta, tau) + delta * tau * phi_r_dt (delta, tau)) / (pow (1. + delta * phi_r_d (delta, tau) - delta * tau * phi_r_dt (delta, tau), 2.) - tau * tau * (phi_0_tt (delta, tau) + phi_r_tt (delta, tau)) * (1. + 2. * delta * phi_r_d (delta, tau) + delta * delta * phi_r_dd (delta, tau)))) / density / massic_gas_constant)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(massic_gibbs_free_energy, (1. + r6::detail::phi_0 (delta, tau) + detail::phi_r (delta, tau) + delta * detail::phi_r_d (delta, tau)) * massic_gas_constant * temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(speed_of_sound, (pow ((1 + 2. * delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau) - pow (1. + delta * detail::phi_r_d (delta, tau) - delta * tau * detail::phi_r_dt (delta, tau), 2) / (tau * tau * (r6::detail::phi_0_tt (delta, tau) + detail::phi_r_tt (delta, tau)))) * massic_gas_constant * temperature, 0.5)))
// AN3, no tests for these
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(isothermal_stress_coefficient, (1. + ((delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau)) / (1. + delta * detail::phi_r_d (delta, tau)))) * density)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(relative_pressure_coefficient, (1. - ((delta * tau * detail::phi_r_dt (delta, tau)) / (1. + delta * detail::phi_r_d (delta, tau)))) / temperature)
ISTO_IAPWS_R6_GENERATE_FUNCTIONS(isobaric_cubic_expansion_coefficient, ((1. + delta * detail::phi_r_d (delta, tau) - delta * tau * detail::phi_r_dt (delta, tau)) / (1. + 2 * delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau))) / temperature)
//ISTO_IAPWS_R6_GENERATE_FUNCTIONS(isothermal_compressibility, (1. / (1. + 2. * delta * detail::phi_r_d (delta, tau) + delta * delta * detail::phi_r_dd (delta, tau))) / density / massic_gas_constant / temperature)
#undef ISTO_IAPWS_R6_GENERATE_FUNCTIONS

} // inline namespace r6_95_2016
} // namespace calculisto::iapws::r6_gas
// vim: foldmethod=marker
