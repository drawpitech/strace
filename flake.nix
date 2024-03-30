{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    utils,
  }:
    utils.lib.eachDefaultSystem (system: let
        pkgs = nixpkgs.legacyPackages.${system};
        cc = pkgs.gcc12;
      in rec
      {
        devShells.default = pkgs.mkShell {
          packages =
            packages.strace.buildInputs
            ++ (with pkgs; [
              hexyl
              ltrace
              strace
              valgrind
              bear
              gdb
            ]);
        };

        formatter = pkgs.alejandra;

        packages = {
          default = packages.strace;
          strace = pkgs.stdenv.mkDerivation rec {
            name = "my_strace";
            src = ./.;

            buildInputs = [cc] ++ (with pkgs; [glibc gnumake]);
            makeFlags = ["CC=${cc}/bin/gcc"];
            hardeningDisable = ["format" "fortify"];
            enableParallelBuilding = true;

            buildPhase = ''
              make ${name}
            '';
            installPhase = ''
              mkdir -p $out/bin
              cp ${name} $out/bin
            '';
          };
        };
      });
}
