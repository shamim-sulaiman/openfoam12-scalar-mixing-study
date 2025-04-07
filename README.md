# 🧪 In-Situ Leaching Simulation (Scalar Transport in OpenFOAM 12)

This project marks my first practical attempt at running a CFD simulation using OpenFOAM. I chose a simple in-situ leaching (ISL) setup — a process used in mining where a fluid is injected into a porous ore body to extract valuable minerals without physically removing the rock.

While the real-world physics are more complex, this case focuses on modeling the scalar transport of a leaching agent in a 2D flow — tracking how it diffuses and mixes over time.

---

## 📘 Background

In-situ leaching (ISL) — also known as in-situ recovery — is a mining technique where a solvent is injected into a porous ore body to dissolve valuable minerals (e.g., copper, uranium). The resulting solution is then pumped back to the surface for processing.

Rather than removing solid ore, ISL relies on underground chemical transport, making it environmentally less invasive but highly dependent on **fluid flow**, **porosity**, **permeability**, and **solute transport mechanisms**.

---

## 🧪 Purpose

This project serves as:
- A visual and verifiable CFD-based representation of scalar transport for **in-situ processes**.
- A template to expand toward **porous media**, **reactive transport**, or **field-scale leaching**.
- A proof-of-concept to **stop simulation dynamically** based on physics (mixing metric).

**This simulation models**:
- A rectangular 2D slice of porous ground.
- Scalar transport of a leaching agent (field `T`) through the domain.
- Advection by a uniform velocity field + molecular diffusion.
- Continuous evaluation of *mixing quality* using a `coded` function.

---

## 🛠️ Simulation Setup

| Aspect                  | Details                                      |
|-------------------------|----------------------------------------------|
| OpenFOAM Version        | v12                                          |
| Solver Framework        | `foamRun` using `functions` solver mode      |
| Geometry                | 2D rectangular block: 1m (L) x 0.5m (H)      |
| Grid                    | 50 × 25 cells                                |
| Scalar Field            | `T` (leaching agent concentration)           |
| Velocity Field          | Uniform inlet flow (1 m/s)                   |
| Boundary Conditions     | `T=1` at inlet, zero gradient elsewhere      |
| Diffusivity             | 1e-5 m²/s (constant)                         |
| End Time                | 500 s                                        |
| Time Step               | 1 s                                          |
| Mixing Stop Condition   | Simulation ends if `mean(T)/max(T) > 0.9`    |

---

## 📈 Results

| Time | Mixing Quality |
|------|----------------|
| 0s   | 0.0995         |
| 20s  | 0.5004         |
| 50s  | 0.7661         |
| 85s  | 0.9003 (Stop)  |

- Simulation stopped at **85s** when the domain reached the desired *homogeneity*.
- Captured visualizations show front propagation and gradual smoothing of scalar field `T`.

---

## 📊 Validation & Comparison

This case is a simplified analogue of scalar tracer experiments often used in:
- Groundwater contaminant transport studies.
- Leach mining feasibility models.
- Mixing tank validation (ideal plug flow with diffusion).

### Governing Equation:

\[
\frac{\partial T}{\partial t} + \nabla \cdot (\vec{U} T) = \nabla \cdot (D \nabla T)
\]

Where:
- `T` is the concentration of leachate,
- `U` is the velocity field,
- `D` is the diffusion coefficient (constant here).
- Solved numerically using **DILUPBiCGStab**

While the geometry and flow are simplified, the results align with expected diffusion-dominated spreading and match the form of analytical/empirical profiles of tracer fronts.

---

## 📁 File Structure

```
insituLeaching2D/
├── 0/                  # Initial conditions (T, U)
├── constant/
│   ├── transportProperties
│   ├── momentumTransport
│   ├── polyMesh/blockMeshDict
├── system/
│   ├── controlDict
│   ├── fvSchemes
│   ├── fvSolution
│   └── functions       # Includes scalarTransport and mixingQualityCheck
├── dynamicCode/        # Compiled coded function for mixing quality
├── log.foamRun         # Log of simulation
└── postProcessing/     # Visual output
```

---

## 📦 How to Run

```bash
blockMesh
foamRun -solver functions > log.foamRun
```

---

## 📸 Visual Output



---

## 📚 References

1. OpenFOAM v12 Documentation – https://openfoam.org
2. Environmental modeling of in-situ leach operations
3. Analytical tracer transport in plug-flow reactors

---

> Feel free to fork, modify, or extend the case for your own research or teaching purposes.
