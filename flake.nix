{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        cc = pkgs.gcc12;
      in
      {
        devShells.default = pkgs.mkShell {
          packages = [ cc ] ++ (with pkgs; [
            glibc
            gnumake
            hexyl
            criterion
            gcovr
            ltrace
            strace
            valgrind
            bear
            gdb
            nasm
          ]);
        };

        formatter = pkgs.nixpkgs-fmt;
      });
}
